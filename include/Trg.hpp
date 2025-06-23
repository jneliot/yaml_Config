#ifndef TRG_HPP
#define TRG_HPP

#include <vector>

int get_EnableL1APhysics() {
    return 0;
}

int get_EnableL1ARandom() {
    return 0;
}

int get_EnableL1ASoftware() {
    return 0;
}

int get_EnableL1ARegular() {
    return 0;
}

int get_L1APrbsThreshold() {
    return 16777195;
}

int get_L1ARegularGap() {
    return 712;
}

int get_EnableNZSRegular() {
    return 0;
}

int get_EnableNZSRandom() {
    return 0;
}

int get_EnableNZSPhysics() {
    return 0;
}

int get_CalComingToL1A() {
    return 510;
}

int get_TTSEnable() {
    return 7;
}

int get_L1APhysicsEnable() {
    return 255;
}

int get_SequencerRunCtrl() {
    return 0;
}

int get_SequencerLength() {
    return 2;
}

std::vector<unsigned int> get_SequencerData() {
    return {15728896, 16056448};
}

int get_Delay() {
    return 0;
}

int get_WindowSelect() {
    return 0;
}

#endif // TRG_HPP