#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include "Slink.hpp"


/*-------------------------------------------------------------------
                                Slink
-------------------------------------------------------------------*/
//-------------------------------------------------------------------
//                           SLink File

int Create_SlinkConfig(string RunId, ofstream& fileOut) {

    fileOut << "Source: SerenitySlink\n";
    fileOut << "BoardId: " << get_BoardId() << "\n";
    fileOut << "Timestamp: " << time(nullptr) << "\n";
    fileOut << "ReferenceClock: " << get_ReferenceClock() << "\n";
    fileOut << "QPllLock: " << get_QPllLock() << "\n";
    fileOut << "NumberOfSlinkQuads: " << get_NumberOfSlinkQuads() << "\n";

    vector<Quad> quads = get_Quads();
    for (const auto& quad : quads) {
        fileOut << "Quad:\n";
        fileOut << "  - SlinkKind: " << quad.SlinkKind << "\n";
        fileOut << "    NumberOfQuadChannels: " << quad.NumberOfQuadChannels << "\n";
        fileOut << "    Channel:\n";
        for (const auto& channel : quad.Channels) {
            fileOut << "      - SourceId: " << channel.SourceId << "\n";
            fileOut << "        CoreStatusAddress: " << channel.CoreStatusAddress << "\n";
        }
    }

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                           Slink Start

int Create_SlinkConfigStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenitySLinkConfigStart.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_SlinkConfig(RunId, fileOut);
}

//-------------------------------------------------------------------
//                          Slink Stop

int Create_SlinkConfigStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenitySLinkConfigStop.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_SlinkConfig(RunId, fileOut);
}