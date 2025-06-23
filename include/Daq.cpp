#include <fstream>
#include <iostream>
#include "Daq.hpp"

using namespace std;

/*-------------------------------------------------------------------
                            Daq Config
-------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                     Daq Config File

int Create_DaqConfig(string RunId, ofstream& fileOut) {

    fileOut << "Source: SerenityDaq\n";
    fileOut << "BoardId: " << get_BoardId() << "\n";
    fileOut << "Timestamp: " << time(nullptr) << "\n";
    fileOut << "DaqControl:\n";
    fileOut << "  Version: " << get_Version() << "\n";

    fileOut << "  NumberOfSLinks: " << get_NumberOfSLinks() << "\n"; // Get the number of SLinks and display their channels
    for(int i = 0; i < get_NumberOfSLinks(); ++i) {
        fileOut << "  SLink: \n";
        fileOut << "    - Channel: \n";
        int* channels = get_Channel(i);
        fileOut << "      CaptureBlockReadStart: " << channels[0] << "\n";
        fileOut << "      CaptureBlockReadEnd: " << channels[1] << "\n";
    }

    fileOut << "  NumberOfLpGbtPairs: " << get_NumberOfLpGbtPairs() << "\n";
    fileOut << "  LpGbtPair: \n";
    for(int i = 0; i < get_NumberOfLpGbtPairs(); ++i) {
        fileOut << "    - Capture: \n";
        fileOut << "      EcondHeaderPattern: " << get_EcondHeaderPattern(i) << "\n";
        fileOut << "      DisableBackpressure: " << get_DisableBackpressure(i) << "\n";
        fileOut << "      AllowBxMismatch: " << get_AllowBxMismatch(i) << "\n";
        fileOut << "      NumberOfEconds: " << get_NumberOfEconds(i) << "\n";

        fileOut << "      EcondMemory:\n";
        for(int j = 0; j < 12; ++j) {
            int* addresses = get_Econd_addresses(i, j);
            fileOut << "        - StartAddress: " << addresses[0] << "\n";
            fileOut << "          EndAddress: " << addresses[1] << "\n";
        }

        fileOut << "      EcondId:\n";
        for(int j = 0; j < 14; ++j) {
            fileOut << "        - Id: "<< get_Econd_Id(i,j) << "\n";
        }

        fileOut << "      FastControl:\n";
        fileOut << "        UserCommand: 54\n";
        fileOut << "        UserCommandBx: 1\n";
        fileOut << "        Stream:\n";
        for(int j = 0; j < 8; ++j) {
            fileOut << "          - CalPulseType: " << get_CalPulseType(i,j) << "\n";
            fileOut << "            LoopUserCommand: " << get_LoopUserCommand(i,j) << "\n";
            fileOut << "            LinkResetCommand: " << get_LinkResetCommand(i,j) << "\n";
        }

        fileOut << "      Decoder:\n";
        fileOut << "        ForceLock: " << get_ForceLock(i) << "\n";
        fileOut << "        PreL1aOffset: " << get_PreL1aOffset(i) << "\n";
    }
    fileOut << "  DaqGlobalCapture:\n";
    fileOut << "    BcrResetValue: " << get_BcrResetValue() << "\n";
    fileOut << "    OcrResetValue: " << get_OcrResetValue() << "\n";
    fileOut << "    TimeoutLimit: " << get_TimeoutLimit() << "\n";
    fileOut << "    EcondIdlePattern: " << get_EcondIdlePattern() << "\n";

    fileOut << "  DaqFastControl:\n";
    fileOut << "    L1aStretch: " << get_L1aStretch() << "\n";
    fileOut << "    SlinkFifoOffset: " << get_SlinkFifoOffset() << "\n";
    fileOut << "    EnableSlinkFifoThrottle: " << get_EnableSlinkFifoThrottle() << "\n";
    fileOut << "    L1aEcrEnable: " << get_L1aEcrEnable() << "\n";
    fileOut << "    OcrEnable: " << get_OcrEnable() << "\n";
    fileOut << "    OcrPeriod: " << get_OcrPeriod() << "\n";
    fileOut << "    PreL1aOffsetOverride3: " << get_PreL1aOffsetOverride3() << "\n";
    fileOut << "    PreL1aOffsetOverride3Enable: " << get_PreL1aOffsetOverride3Enable() << "\n";
    fileOut << "    CalPulseIntDelay: " << get_CalPulseIntDelay() << "\n";
    fileOut << "    CalPulseExtDelay: " << get_CalPulseExtDelay() << "\n";




    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                          Daq Start
int Create_DaqConfigStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityDaqConfigStart.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_DaqConfig(RunId, fileOut);
}

//-------------------------------------------------------------------
//                          Daq Stop

int Create_DaqConfigStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityDaqConfigStop.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_DaqConfig(RunId, fileOut);
}

/*-------------------------------------------------------------------
                            Daq Status
-------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                      Daq Status File

int Create_DaqStatus(string RunId, ofstream& fileOut) {

    fileOut << "Source: SerenityDaq\n";
    fileOut << "BoardId: " << get_BoardId() << "\n";
    fileOut << "Timestamp: " << time(nullptr) << "\n";
    fileOut << "DaqControl:\n";
    fileOut << "  NumberOfSlinks: " << get_NumberOfSLinks() << "\n";

    for (int i = 0; i < get_NumberOfSLinks(); ++i) {
        fileOut << "  Slink:\n";
        fileOut << "    - Channel:\n";
        fileOut << "      HeaderCounter: " << get_HeaderCounter(i) << "\n";
        fileOut << "      TrailerCounter: " << get_TrailerCounter(i) << "\n";
    }

    fileOut << "  NumberOfLpGbtPairs: " << get_NumberOfLpGbtPairs() << "\n";
    fileOut << "  LpGbtPair:\n";
    for (int i = 0; i < get_NumberOfLpGbtPairs(); ++i) {
        fileOut << "    - Capture:\n";
        fileOut << "      EventCounter: " << get_EventCounter(i) << "\n";
        fileOut << "      NumberOfEconds: " << get_NumberOfEconds(i) << "\n";

        if (get_NumberOfEconds(i) > 0) {
            fileOut << "      Econd:\n";
            for (int j = 0; j < get_NumberOfEconds(i); ++j) {
                fileOut << "        - LatchedIdleError: " << get_LatchedIdleError(i, j) << "\n";
                fileOut << "          NumberOfCrcErrors: " << get_NumberOfCrcErrors(i, j) << "\n";
            }
        }

        fileOut << "      FastControl:\n";
        fileOut << "        IntegratedStatus: " << get_IntegratedStatus() << "\n";
        fileOut << "      Decoder:\n";
        fileOut << "        IntegratedStatus: " << get_IntegratedStatus() << "\n";
    }

    fileOut << "  DaqGlobalCapture:\n";
    fileOut << "    IntegratedStatus: " << get_IntegratedStatus() << "\n";

    fileOut << "  DaqFastControl:\n";
    fileOut << "    EventCounter: " << get_EventCounter(0) << "\n";
    fileOut << "    OrbitCounter: " << get_OrbitCounter() << "\n";
    fileOut << "    SlinkFifoMaxOccupancy: " << get_SlinkFifoMaxOccupancy() << "\n";
    fileOut << "    SlinkFifoFullRisingEdgeCounter: " << get_SlinkFifoFullRisingEdgeCounter() << "\n";
    fileOut << "    SlinkFifoWriteEnableCounter: " << get_SlinkFifoWriteEnableCounter() << "\n";
    fileOut << "    SlinkFifoReadEnableCounter: " << get_SlinkFifoReadEnableCounter() << "\n";

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                          Daq Start

int Create_DaqStatusStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityDaqStatusStart.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_DaqStatus(RunId, fileOut);
}

//-------------------------------------------------------------------
//                          Daq Stop

int Create_DaqStatusStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityDaqStatusStop.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_DaqStatus(RunId, fileOut);
}