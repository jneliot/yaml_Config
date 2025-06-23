#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include "Trg.hpp"

using namespace std;

/*-------------------------------------------------------------------
                             Trg Config
 -------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                      Trg Config File

int Create_TrgConfig(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTrgConfigurationStart.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    cout << "Source: SerenityTrg\n";
    cout << "BoardId: " << get_BoardId() << "\n";
    cout << "Timestamp: " << time(nullptr) << "\n";
    cout << "TrgTcds2e:\n";
    cout << "  EnableL1APhysics: " << get_EnableL1APhysics() << "\n";
    cout << "  EnableL1ARandom: " << get_EnableL1ARandom() << "\n";
    cout << "  EnableL1ASoftware: " << get_EnableL1ASoftware() << "\n";
    cout << "  EnableL1ARegular: " << get_EnableL1ARegular() << "\n";
    cout << "  L1APrbsThreshold: " << get_L1APrbsThreshold() << "\n";
    cout << "  L1ARegularGap: " << get_L1ARegularGap() << "\n";
    cout << "  EnableNZSRegular: " << get_EnableNZSRegular() << "\n";
    cout << "  EnableNZSRandom: " << get_EnableNZSRandom() << "\n";
    cout << "  EnableNZSPhysics: " << get_EnableNZSPhysics() << "\n";
    cout << "  CalComingToL1A: " << get_CalComingToL1A() << "\n";
    cout << "  TTSEnable: " << get_TTSEnable() << "\n";
    cout << "  L1APhysicsEnable: " << get_L1APhysicsEnable() << "\n";
    cout << "  SequencerRunCtrl: " << get_SequencerRunCtrl() << "\n";
    cout << "  SequencerLength: " << get_SequencerLength() << "\n";
    cout << "  SequencerData:\n";

    vector<unsigned int> sequencerData = get_SequencerData();
    for (const auto& data : sequencerData) {
        cout << "    - " << data << "\n";
    }

    cout << "TrgExternal:\n";
    cout << "  Delay: " << get_Delay() << "\n";
    cout << "  WindowSelect: " << get_WindowSelect() << "\n";

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                           Trg Start

int Create_TrgConfigStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTrgConfigStart.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TrgConfig(RunId);
}

//-------------------------------------------------------------------
//                          Trg Stop

int Create_TrgConfigStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTrgConfigStop.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TrgConfig(RunId);
}



/*-------------------------------------------------------------------
                             Trg Status
 -------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                      Trg status File

int Create_TrgStatus(string RunId) {

    cout << "Source: SerenityTrg\n";
    cout << "BoardId: " << get_BoardId() << "\n";
    cout << "Timestamp: " << time(nullptr) << "\n";
    cout << "TrgControl:\n";
    cout << "  NumberOfLpGbtPairs: " << get_NumberOfLpGbtPairs() << "\n";
    cout << "  LpGbtPair:\n";

    for (int i = 0; i < get_NumberOfLpGbtPairs(); ++i) {
        cout << "    - UnpackerBlock:\n";
        cout << "      NumberOfUnpackers: " << get_NumberOfUnpackers(i) << "\n";
        cout << "      Counters:\n";
        for (int j = 0; j < get_NumberOfUnpackers(i); ++j) {
            cout << "        - Locked: " << get_Locked(i, j) << "\n";
            cout << "          ValidPacket: " << get_ValidPacket(i, j) << "\n";
            cout << "          Bc0Packet: " << get_Bc0Packet(i, j) << "\n";
        }
        cout << "      SelfTrigger:\n";
        cout << "        TriggerCounter: " << get_TriggerCounter(i) << "\n";
    }

    cout << "  TrgReadout:\n";
    cout << "    SlinkBackpressureLatch: " << get_SlinkBackpressureLatch() << "\n";
    cout << "    PacketCount: " << get_PacketCount() << "\n";
    cout << "    NumberOfChannels: " << get_NumberOfChannels() << "\n";
    cout << "    Channel:\n";
    for (int i = 0; i < get_NumberOfChannels(); ++i) {
        cout << "      - EventBufferMaxOccupancy: " << get_EventBufferMaxOccupancy(i) << "\n";
        cout << "        EventBufferOverflow: " << get_EventBufferOverflow(i) << "\n";
        cout << "        AddressBufferOverflow: " << get_AddressBufferOverflow(i) << "\n";
    }

    cout << "  TrgFastControl:\n";
    cout << "    EventCounter: " << get_EventCounter() << "\n";
    cout << "    OrbitCounter: " << get_OrbitCounter() << "\n";
    cout << "    SlinkFifoMaxOccupancy: " << get_SlinkFifoMaxOccupancy() << "\n";
    cout << "    SlinkFifoFullRisingEdgeCounter: " << get_SlinkFifoFullRisingEdgeCounter() << "\n";
    cout << "    SlinkFifoWriteEnableCounter: " << get_SlinkFifoWriteEnableCounter() << "\n";
    cout << "    SlinkFifoReadEnableCounter: " << get_SlinkFifoReadEnableCounter() << "\n";

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                           Trg Start

int Create_TrgStatusStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTrgStatusStart.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TrgStatus(RunId);
}

//-------------------------------------------------------------------
//                          Trg Stop

int Create_TrgStatusStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTrgStatusStop.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TrgStatus(RunId);
}