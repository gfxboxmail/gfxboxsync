#include <iostream>

int main(int argc, char** argv) {
    std::cout << "GFXBox Sync standalone\n";
    if (argc < 3) {
        std::cout << "Usage: gfxboxsync_standalone <reference.wav> <candidate.wav>\n";
        return 1;
    }

    std::cout << "Audio decoding and desktop UI integration are pending.\n";
    return 0;
}
