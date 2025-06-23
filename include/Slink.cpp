#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include "Slink.hpp"


/*-------------------------------------------------------------------
                                Slink
-------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                           Slink Start

int Create_SlinkConfigStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenitySLinkConfigStart.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_SlinkConfig(RunId);
}

//-------------------------------------------------------------------
//                          Slink Stop

int Create_SlinkConfigStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenitySLinkConfigStop.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_SlinkConfig(RunId);
}

//-------------------------------------------------------------------
//                      SLink File

int Create_SlinkConfig(string RunId) {

    cout << "Source: SerenitySlink\n";
    cout << "BoardId: " << get_BoardId() << "\n";
    cout << "Timestamp: " << time(nullptr) << "\n";
    cout << "ReferenceClock: " << get_ReferenceClock() << "\n";
    cout << "QPllLock: " << get_QPllLock() << "\n";
    cout << "NumberOfSlinkQuads: " << get_NumberOfSlinkQuads() << "\n";

    vector<Quad> quads = get_Quads();
    for (const auto& quad : quads) {
        cout << "Quad:\n";
        cout << "  - SlinkKind: " << quad.SlinkKind << "\n";
        cout << "    NumberOfQuadChannels: " << quad.NumberOfQuadChannels << "\n";
        cout << "    Channel:\n";
        for (const auto& channel : quad.Channels) {
            cout << "      - SourceId: " << channel.SourceId << "\n";
            cout << "        CoreStatusAddress: " << channel.CoreStatusAddress << "\n";
        }
    }

    return EXIT_SUCCESS;
}
