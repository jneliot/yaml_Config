#include <fstream>
#include <iostream>
#include "Daq.hpp"

using namespace std;

/*-------------------------------------------------------------------
                            Daq Config
-------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                     Daq Config File

int Create_DaqConfig(string RunId) {

    cout << "Source: SerenityDaq\n";
    cout << "BoardId: " << get_BoardId() << "\n";
    cout << "Timestamp: " << time(nullptr) << "\n";
    cout << "DaqControl:\n";
    cout << "  Version: " << get_Version() << "\n";

    cout << "  NumberOfSLinks: " << get_NumberOfSLinks() << "\n"; // Get the number of SLinks and display their channels
    for(int i = 0; i < get_NumberOfSLinks(); ++i) {
        cout << "  SLink: \n";
        cout << "    - Channel: \n";
        int* channels = get_Channel(i);
        cout << "      CaptureBlockReadStart: " << channels[0] << "\n";
        cout << "      CaptureBlockReadEnd: " << channels[1] << "\n";
    }

    cout << "  NumberOfLpGbtPairs: " << get_NumberOfLpGbtPairs() << "\n";
    cout << "  LpGbtPair: \n";
    for(int i = 0; i < get_NumberOfLpGbtPairs(); ++i) {
        cout << "    - Capture: \n";
        cout << "      EcondHeaderPattern: " << get_EcondHeaderPattern(i) << "\n";
        cout << "      DisableBackpressure: " << get_DisableBackpressure(i) << "\n";
        cout << "      AllowBxMismatch: " << get_AllowBxMismatch(i) << "\n";
        cout << "      NumberOfEconds: " << get_NumberOfEconds(i) << "\n";

        cout << "      EcondMemory:\n";
        for(int j = 0; j < 12; ++j) {
            int* addresses = get_Econd_addresses(i, j);
            cout << "        - StartAddress: " << addresses[0] << "\n";
            cout << "          EndAddress: " << addresses[1] << "\n";
        }

        cout << "      EcondId:\n";
        for(int j = 0; j < 14; ++j) {
            cout << "        - Id: "<< get_Econd_Id(i,j) << "\n";
        }

        cout << "      FastControl:\n";
        cout << "        UserCommand: 54\n";
        cout << "        UserCommandBx: 1\n";
        cout << "        Stream:\n";
        for(int j = 0; j < 8; ++j) {
            cout << "          - CalPulseType: " << get_CalPulseType(i,j) << "\n";
            cout << "            LoopUserCommand: " << get_LoopUserCommand(i,j) << "\n";
            cout << "            LinkResetCommand: " << get_LinkResetCommand(i,j) << "\n";
        }

        cout << "      Decoder:\n";
        cout << "        ForceLock: " << get_ForceLock(i) << "\n";
        cout << "        PreL1aOffset: " << get_PreL1aOffset(i) << "\n";
    }
    cout << "  DaqGlobalCapture:\n";
    cout << "    BcrResetValue: " << get_BcrResetValue() << "\n";
    cout << "    OcrResetValue: " << get_OcrResetValue() << "\n";
    cout << "    TimeoutLimit: " << get_TimeoutLimit() << "\n";
    cout << "    EcondIdlePattern: " << get_EcondIdlePattern() << "\n";

    cout << "  DaqFastControl:\n";
    cout << "    L1aStretch: " << get_L1aStretch() << "\n";
    cout << "    SlinkFifoOffset: " << get_SlinkFifoOffset() << "\n";
    cout << "    EnableSlinkFifoThrottle: " << get_EnableSlinkFifoThrottle() << "\n";
    cout << "    L1aEcrEnable: " << get_L1aEcrEnable() << "\n";
    cout << "    OcrEnable: " << get_OcrEnable() << "\n";
    cout << "    OcrPeriod: " << get_OcrPeriod() << "\n";
    cout << "    PreL1aOffsetOverride3: " << get_PreL1aOffsetOverride3() << "\n";
    cout << "    PreL1aOffsetOverride3Enable: " << get_PreL1aOffsetOverride3Enable() << "\n";
    cout << "    CalPulseIntDelay: " << get_CalPulseIntDelay() << "\n";
    cout << "    CalPulseExtDelay: " << get_CalPulseExtDelay() << "\n";




    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                          Daq Start
int Create_DaqConfigStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityDaqConfigStart.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_DaqConfig(RunId);
}

//-------------------------------------------------------------------
//                          Daq Stop

int Create_DaqConfigStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityDaqConfigStop.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_DaqConfig(RunId);
}

/*-------------------------------------------------------------------
                            Daq Status
-------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                      Daq Status File

int Create_DaqStatus(string RunId) {

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

//-------------------------------------------------------------------
//                          Daq Start

int Create_DaqStatusStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityDaqStatusStart.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_DaqStatus(RunId);
}

//-------------------------------------------------------------------
//                          Daq Stop

int Create_DaqStatusStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityDaqStatusStop.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_DaqStatus(RunId);
}