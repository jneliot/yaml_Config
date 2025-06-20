#include <fstream>
#include <iostream>
#include "DaqConfig.hpp"

using namespace std;

int Create_DaqConfigStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityDaqConfigurationStart.yaml";

    ofstream cout(filename.c_str()); //Open the file for writing with cout
    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

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
    for(int i = 0; i < get_NumberOfLpGbtPairs(); ++i) {
        cout << "  LpGbtPair: \n";
        cout << "    - Capture: \n";
        cout << "      EcondHeaderPattern: " << get_EcondHeaderPattern(i) << "\n";
        cout << "      DisableBackpressure: " << get_DisableBackpressure(i) << "\n";
        cout << "      AllowBxMismatch: " << get_AllowBxMismatch(i) << "\n";
        cout << "      NumberOfEconds: " << get_NumberOfEconds(i) << "\n";

        cout << "      EcondMemory:\n";
        for(int j = 0; j < 8; ++j) {
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
    cout << "    CalPulseExtDelay: 1" << get_CalPulseExtDelay() << "\n";




    return EXIT_SUCCESS;
}