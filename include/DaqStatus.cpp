#include <fstream>
#include <iostream>
#include <string>
#include "DaqStatus.hpp"

using namespace std;

int Create_DaqStatusStart(string RunId) {

    string filename = RunId + "/" + RunId + "_SerenityDaqStatusStart.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    cout << "Source: SerenityDaq\n";
    cout << "BoardId: " << get_BoardId() << "\n";
    cout << "Timestamp: " << time(nullptr) << "\n";
    cout << "DaqControl:\n";
    cout << "  NumberOfSlinks: " << get_NumberOfSLinks() << "\n";

    for (int i = 0; i < get_NumberOfSLinks(); ++i) {
        cout << "  Slink:\n";
        cout << "    - Channel:\n";
        cout << "      HeaderCounter: " << get_HeaderCounter(i) << "\n";
        cout << "      TrailerCounter: " << get_TrailerCounter(i) << "\n";
    }

    cout << "  NumberOfLpGbtPairs: " << get_NumberOfLpGbtPairs() << "\n";
    cout << "  LpGbtPair:\n";
    for (int i = 0; i < get_NumberOfLpGbtPairs(); ++i) {
        cout << "    - Capture:\n";
        cout << "      EventCounter: " << get_EventCounter(i) << "\n";
        cout << "      NumberOfEconds: " << get_NumberOfEconds(i) << "\n";

        if (get_NumberOfEconds(i) > 0) {
            cout << "      Econd:\n";
            for (int j = 0; j < get_NumberOfEconds(i); ++j) {
                cout << "        - LatchedIdleError: " << get_LatchedIdleError(i, j) << "\n";
                cout << "          NumberOfCrcErrors: " << get_NumberOfCrcErrors(i, j) << "\n";
            }
        }

        cout << "      FastControl:\n";
        cout << "        IntegratedStatus: " << get_IntegratedStatus() << "\n";
        cout << "      Decoder:\n";
        cout << "        IntegratedStatus: " << get_IntegratedStatus() << "\n";
    }

    cout << "  DaqGlobalCapture:\n";
    cout << "    IntegratedStatus: " << get_IntegratedStatus() << "\n";

    cout << "  DaqFastControl:\n";
    cout << "    EventCounter: " << get_EventCounter(0) << "\n";
    cout << "    OrbitCounter: " << get_OrbitCounter() << "\n";
    cout << "    SlinkFifoMaxOccupancy: " << get_SlinkFifoMaxOccupancy() << "\n";
    cout << "    SlinkFifoFullRisingEdgeCounter: " << get_SlinkFifoFullRisingEdgeCounter() << "\n";
    cout << "    SlinkFifoWriteEnableCounter: " << get_SlinkFifoWriteEnableCounter() << "\n";
    cout << "    SlinkFifoReadEnableCounter: " << get_SlinkFifoReadEnableCounter() << "\n";

    return EXIT_SUCCESS;
}