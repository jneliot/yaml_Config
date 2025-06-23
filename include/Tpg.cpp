#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include "Tpg.hpp"

using namespace std;

/*-------------------------------------------------------------------
                             Tpg Config
 -------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                        Tpg Config File

int Create_TpgConfig(string RunId,  ofstream& fileOut) {

    fileOut << "Source: SerenityTpg\n";
    fileOut << "BoardId: " << get_BoardId() << "\n";
    fileOut << "Timestamp: " << time(nullptr) << "\n";
    fileOut << "TpgControl:\n";
    fileOut << "  SelfTriggerDelay: " << get_SelfTriggerDelay() << "\n";
    fileOut << "  NumberOfLpGbtPairs: " << get_NumberOfLpGbtPairs() << "\n";
    fileOut << "  LpGbtPair:\n";

    for (int i = 0; i < get_NumberOfLpGbtPairs(); ++i) {
        fileOut << "    - UnpackerBlock:\n";
        fileOut << "      BxLatency: " << get_BxLatency(i) << "\n";
        fileOut << "      Stc4AUnpackerDelay: " << get_Stc4AUnpackerDelay(i) << "\n";
        fileOut << "      Stc16UnpackerDelay: " << get_Stc16UnpackerDelay(i) << "\n";
        fileOut << "      NumberOfUnpackers: " << get_NumberOfUnpackers(i) << "\n";
        fileOut << "      Unpackers:\n";
        for (int j = 0; j < get_NumberOfUnpackers(i); ++j) {
            fileOut << "        - Type: " << get_UnpackerType(i, j) << "\n";
        }
        fileOut << "      SelfTrigger:\n";
        fileOut << "        NumberOfEconts: " << get_NumberOfEconts(i) << "\n";
        fileOut << "        Econt:\n";
        for (int j = 0; j < get_NumberOfEconts(i); ++j) {
            fileOut << "          - EcontThreshold: " << get_EcontThreshold(i, j) << "\n";
            fileOut << "            TcEnableBits: " << get_TcEnableBits(i, j) << "\n";
            fileOut << "            EcontEnable: " << get_EcontEnable(i, j) << "\n";
        }
    }

    fileOut << "  TpgReadout:\n";
    fileOut << "    BackpressureDisable: " << get_BackpressureDisable() << "\n";
    fileOut << "    NumberOfChannels: " << get_NumberOfChannels() << "\n";
    fileOut << "    Channel:\n";
    for (int i = 0; i < get_NumberOfChannels(); ++i) {
        fileOut << "      - Latency: " << get_ChannelLatency(i) << "\n";
        fileOut << "        TmuxId: " << get_TmuxId(i) << "\n";
        fileOut << "        ReadoutWindow: " << get_ReadoutWindow(i) << "\n";
        fileOut << "        WordsPerBx: " << get_WordsPerBx(i) << "\n";
        fileOut << "        Masked: " << get_Masked(i) << "\n";
    }

    fileOut << "  TpgFastControl:\n";
    fileOut << "    L1aStretch: " << get_L1aStretch() << "\n";
    fileOut << "    SlinkFifoOffset: " << get_SlinkFifoOffset() << "\n";
    fileOut << "    EnableSlinkFifoThrottle: " << get_EnableSlinkFifoThrottle() << "\n";

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                           Tpg Start

int Create_TpgConfigStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTpgConfigStart.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TpgConfig(RunId, fileOut);
}

//-------------------------------------------------------------------
//                          Tpg Stop

int Create_TpgConfigStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTpgConfigStop.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TpgConfig(RunId, fileOut);
}


/*-------------------------------------------------------------------
                             Tpg Status
 -------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                      Tpg status File

int Create_TpgStatus(string RunId, ofstream& fileOut) {

    fileOut << "Source: SerenityTpg\n";
    fileOut << "BoardId: " << get_BoardId() << "\n";
    fileOut << "Timestamp: " << time(nullptr) << "\n";
    fileOut << "TpgControl:\n";
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

    fileOut << "  TpgReadout:\n";
    fileOut << "    SlinkBackpressureLatch: " << get_SlinkBackpressureLatch() << "\n";
    fileOut << "    PacketCount: " << get_PacketCount() << "\n";
    fileOut << "    NumberOfChannels: " << get_NumberOfChannels() << "\n";
    fileOut << "    Channel:\n";
    for (int i = 0; i < get_NumberOfChannels(); ++i) {
        fileOut << "      - EventBufferMaxOccupancy: " << get_EventBufferMaxOccupancy(i) << "\n";
        fileOut << "        EventBufferOverflow: " << get_EventBufferOverflow(i) << "\n";
        fileOut << "        AddressBufferOverflow: " << get_AddressBufferOverflow(i) << "\n";
    }

    fileOut << "  TpgFastControl:\n";
    fileOut << "    EventCounter: " << get_EventCounter() << "\n";
    fileOut << "    OrbitCounter: " << get_OrbitCounter() << "\n";
    fileOut << "    SlinkFifoMaxOccupancy: " << get_SlinkFifoMaxOccupancy() << "\n";
    fileOut << "    SlinkFifoFullRisingEdgeCounter: " << get_SlinkFifoFullRisingEdgeCounter() << "\n";
    fileOut << "    SlinkFifoWriteEnableCounter: " << get_SlinkFifoWriteEnableCounter() << "\n";
    fileOut << "    SlinkFifoReadEnableCounter: " << get_SlinkFifoReadEnableCounter() << "\n";

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                           Tpg Start

int Create_TpgStatusStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTpgStatusStart.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TpgStatus(RunId, fileOut);
}

//-------------------------------------------------------------------
//                          Tpg Stop

int Create_TpgStatusStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTpgStatusStop.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TpgStatus(RunId, fileOut);
}