#include "gfxboxsync/audiomatcher.h"

#include <algorithm>
#include <cmath>
#include <limits>

namespace gfxboxsync {

AudioMatcher::AudioMatcher(BandSettings settings)
    : settings_(settings) {
    if (settings_.bands < 1) settings_.bands = 1;
    if (settings_.frames_per_second < 1) settings_.frames_per_second = 1;
}

MatchResult AudioMatcher::find_offset(
    const std::vector<float>& reference,
    std::size_t reference_sample_rate,
    const std::vector<float>& candidate,
    std::size_t candidate_sample_rate,
    double maximum_search_seconds) const {

    MatchResult best;
    if (reference.empty() || candidate.empty() || reference_sample_rate == 0 || candidate_sample_rate == 0) {
        return best;
    }

    const std::size_t resample_rate = 8000;
    auto resample = [resample_rate](const std::vector<float>& input, std::size_t source_rate) {
        if (source_rate == resample_rate) return input;
        const std::size_t count = static_cast<std::size_t>(
            input.size() * static_cast<double>(resample_rate) / source_rate);
        std::vector<float> output(count);
        for (std::size_t i = 0; i < count; ++i) {
            const double position = i * static_cast<double>(source_rate) / resample_rate;
            const auto index = static_cast<std::size_t>(position);
            if (index < input.size()) output[i] = input[index];
        }
        return output;
    };

    const auto ref = resample(reference, reference_sample_rate);
    const auto cand = resample(candidate, candidate_sample_rate);

    const std::size_t window = std::min<std::size_t>(
        ref.size(), std::min(cand.size(), resample_rate * 5));
    if (window < 16) return best;

    const std::size_t max_shift = static_cast<std::size_t>(
        std::min<double>(maximum_search_seconds * resample_rate,
                         std::max(ref.size(), cand.size()) - window));

    double best_score = -std::numeric_limits<double>::infinity();
    std::size_t best_shift = 0;

    for (std::size_t shift = 0; shift <= max_shift; ++shift) {
        double dot = 0.0;
        double ref_energy = 0.0;
        double cand_energy = 0.0;

        for (std::size_t i = 0; i < window; ++i) {
            if (shift + i >= cand.size()) break;
            const float a = ref[i];
            const float b = cand[shift + i];
            dot += a * b;
            ref_energy += a * a;
            cand_energy += b * b;
        }

        const double denominator = std::sqrt(ref_energy * cand_energy);
        const double correlation = denominator > 0.0 ? dot / denominator : 0.0;
        if (correlation > best_score) {
            best_score = correlation;
            best_shift = shift;
        }
    }

    best.offset_seconds = static_cast<double>(best_shift) / resample_rate;
    best.confidence = std::clamp(best_score, 0.0, 1.0);
    return best;
}

}  // namespace gfxboxsync
