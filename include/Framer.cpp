#include <fstream>
#include <iostream>
#include "Framer.hpp"

using namespace std;

/*-------------------------------------------------------------------
                             Framer Config
 -------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                    Framer Config File

 int Create_FramerConfig(string RunId, ofstream& fileOut) {

    fileOut << "Source: SerenityFramer\n";
    fileOut << "BoardId: " << get_BoardId() << "\n";
    fileOut << "Timestamp: " << time(nullptr) << "\n";
    fileOut << "Framer:\n";
    fileOut << "  LpGbtMGT:\n";

    vector<Link> links = get_LpGbtMGT();
    for (const auto& link : links) {
        fileOut << "    - Link: " << link.LinkNumber << "\n";
        fileOut << "      Elink:\n";
        for (const auto& elink : link.Elinks) {
            fileOut << "        - Address: " << elink.Address << "\n";
            fileOut << "          Shift: " << elink.Shift << "\n";
        }
    }

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                           Framer Start

int Create_FramerConfigStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityFramerConfigStart.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_FramerConfig(RunId, fileOut);
}

//-------------------------------------------------------------------
//                          Framer Stop

int Create_FramerConfigStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityFramerConfigStop.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_FramerConfig(RunId, fileOut);
}