#include "gfxboxsync/audiomatcher.h"

#include <cassert>
#include <vector>

int main() {
    std::vector<float> reference(8000, 0.0f);
    std::vector<float> candidate(16000, 0.0f);

    for (std::size_t i = 1000; i < 8000; ++i) {
        reference[i] = static_cast<float>(std::sin(i * 0.25));
        candidate[i + 1000] = static_cast<float>(std::sin(i * 0.25));
    }

    gfxboxsync::AudioMatcher matcher;
    const auto result = matcher.find_offset(reference, 8000, candidate, 8000, 30.0);

    assert(result.offset_seconds >= 0.125 && result.offset_seconds <= 0.125);
    assert(result.confidence > 0.99);
}
