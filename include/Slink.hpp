#ifndef SLINK_HPP
#define SLINK_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a Channel
struct Channel {
    unsigned int SourceId;
    int CoreStatusAddress;
};

// Structure te represent a Quad
struct Quad {
    int SlinkKind;
    int NumberOfQuadChannels;
    vector<Channel> Channels;
};


vector<Quad> get_Quads() {
    vector<Quad> quads = {
        {5, 2, {{3722304989, 0}, {2863311530, 0}}}
    };
    return quads;
}

int get_ReferenceClock() {
    return 2;
}

int get_QPllLock() {
    return 1;
}

int get_NumberOfSlinkQuads() {
    return 1;
}

#endif // SLINK_HPP