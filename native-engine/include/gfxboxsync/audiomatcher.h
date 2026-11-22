#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

namespace gfxboxsync {

struct MatchResult {
    double offset_seconds = 0.0;
    double confidence = 0.0;
};

struct BandSettings {
    int bands = 16;
    int frames_per_second = 20;
};

class AudioMatcher {
public:
    explicit AudioMatcher(BandSettings settings = {});

    MatchResult find_offset(
        const std::vector<float>& reference,
        std::size_t reference_sample_rate,
        const std::vector<float>& candidate,
        std::size_t candidate_sample_rate,
        double maximum_search_seconds = 30.0) const;

private:
    BandSettings settings_;
};

}  // namespace gfxboxsync
