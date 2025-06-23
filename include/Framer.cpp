#include <fstream>
#include <iostream>
#include "Framer.hpp"

using namespace std;

/*-------------------------------------------------------------------
                             Framer Config
 -------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                    Framer Config File

 int Create_FramerConfig(string RunId) {

    cout << "Source: SerenityFramer\n";
    cout << "BoardId: " << get_BoardId() << "\n";
    cout << "Timestamp: " << time(nullptr) << "\n";
    cout << "Framer:\n";
    cout << "  LpGbtMGT:\n";

    vector<Link> links = get_LpGbtMGT();
    for (const auto& link : links) {
        cout << "    - Link: " << link.LinkNumber << "\n";
        cout << "      Elink:\n";
        for (const auto& elink : link.Elinks) {
            cout << "        - Address: " << elink.Address << "\n";
            cout << "          Shift: " << elink.Shift << "\n";
        }
    }

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                           Framer Start

int Create_FramerConfigStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityFramerConfigStart.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_FramerConfig(RunId);
}

//-------------------------------------------------------------------
//                          Framer Stop

int Create_FramerConfigStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityFramerConfigStop.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_FramerConfig(RunId);
}