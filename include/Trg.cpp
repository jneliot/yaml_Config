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

int Create_TrgConfig(string RunId,  ofstream& fileOut) {

    fileOut << "Source: SerenityTrg\n";
    fileOut << "BoardId: " << get_BoardId() << "\n";
    fileOut << "Timestamp: " << time(nullptr) << "\n";
    fileOut << "TrgTcds2e:\n";
    fileOut << "  EnableL1APhysics: " << get_EnableL1APhysics() << "\n";
    fileOut << "  EnableL1ARandom: " << get_EnableL1ARandom() << "\n";
    fileOut << "  EnableL1ASoftware: " << get_EnableL1ASoftware() << "\n";
    fileOut << "  EnableL1ARegular: " << get_EnableL1ARegular() << "\n";
    fileOut << "  L1APrbsThreshold: " << get_L1APrbsThreshold() << "\n";
    fileOut << "  L1ARegularGap: " << get_L1ARegularGap() << "\n";
    fileOut << "  EnableNZSRegular: " << get_EnableNZSRegular() << "\n";
    fileOut << "  EnableNZSRandom: " << get_EnableNZSRandom() << "\n";
    fileOut << "  EnableNZSPhysics: " << get_EnableNZSPhysics() << "\n";
    fileOut << "  CalComingToL1A: " << get_CalComingToL1A() << "\n";
    fileOut << "  TTSEnable: " << get_TTSEnable() << "\n";
    fileOut << "  L1APhysicsEnable: " << get_L1APhysicsEnable() << "\n";
    fileOut << "  SequencerRunCtrl: " << get_SequencerRunCtrl() << "\n";
    fileOut << "  SequencerLength: " << get_SequencerLength() << "\n";
    fileOut << "  SequencerData:\n";

    vector<unsigned int> sequencerData = get_SequencerData();
    for (const auto& data : sequencerData) {
        fileOut << "    - " << data << "\n";
    }

    fileOut << "TrgExternal:\n";
    fileOut << "  Delay: " << get_Delay() << "\n";
    fileOut << "  WindowSelect: " << get_WindowSelect() << "\n";

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                           Trg Start

int Create_TrgConfigStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTrgConfigStart.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TrgConfig(RunId, fileOut);
}

//-------------------------------------------------------------------
//                          Trg Stop

int Create_TrgConfigStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTrgConfigStop.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TrgConfig(RunId, fileOut);
}



/*-------------------------------------------------------------------
                             Trg Status
 -------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                      Trg status File

int Create_TrgStatus(string RunId, ofstream& fileOut) {

    fileOut << "Source: SerenityTrg\n";
    fileOut << "BoardId: " << get_BoardId() << "\n";
    fileOut << "Timestamp: " << time(nullptr) << "\n";
    fileOut << "TrgControl:\n";
    fileOut << "  NumberOfLpGbtPairs: " << get_NumberOfLpGbtPairs() << "\n";
    fileOut << "  LpGbtPair:\n";

    for (int i = 0; i < get_NumberOfLpGbtPairs(); ++i) {
        fileOut << "    - UnpackerBlock:\n";
        fileOut << "      NumberOfUnpackers: " << get_NumberOfUnpackers(i) << "\n";
        fileOut << "      Counters:\n";
        for (int j = 0; j < get_NumberOfUnpackers(i); ++j) {
            fileOut << "        - Locked: " << get_Locked(i, j) << "\n";
            fileOut << "          ValidPacket: " << get_ValidPacket(i, j) << "\n";
            fileOut << "          Bc0Packet: " << get_Bc0Packet(i, j) << "\n";
        }
        fileOut << "      SelfTrigger:\n";
        fileOut << "        TriggerCounter: " << get_TriggerCounter(i) << "\n";
    }

    fileOut << "  TrgReadout:\n";
    fileOut << "    SlinkBackpressureLatch: " << get_SlinkBackpressureLatch() << "\n";
    fileOut << "    PacketCount: " << get_PacketCount() << "\n";
    fileOut << "    NumberOfChannels: " << get_NumberOfChannels() << "\n";
    fileOut << "    Channel:\n";
    for (int i = 0; i < get_NumberOfChannels(); ++i) {
        fileOut << "      - EventBufferMaxOccupancy: " << get_EventBufferMaxOccupancy(i) << "\n";
        fileOut << "        EventBufferOverflow: " << get_EventBufferOverflow(i) << "\n";
        fileOut << "        AddressBufferOverflow: " << get_AddressBufferOverflow(i) << "\n";
    }

    fileOut << "  TrgFastControl:\n";
    fileOut << "    EventCounter: " << get_EventCounter() << "\n";
    fileOut << "    OrbitCounter: " << get_OrbitCounter() << "\n";
    fileOut << "    SlinkFifoMaxOccupancy: " << get_SlinkFifoMaxOccupancy() << "\n";
    fileOut << "    SlinkFifoFullRisingEdgeCounter: " << get_SlinkFifoFullRisingEdgeCounter() << "\n";
    fileOut << "    SlinkFifoWriteEnableCounter: " << get_SlinkFifoWriteEnableCounter() << "\n";
    fileOut << "    SlinkFifoReadEnableCounter: " << get_SlinkFifoReadEnableCounter() << "\n";

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                           Trg Start

int Create_TrgStatusStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTrgStatusStart.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TrgStatus(RunId, fileOut);
}

//-------------------------------------------------------------------
//                          Trg Stop

int Create_TrgStatusStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTrgStatusStop.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TrgStatus(RunId, fileOut);
}