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
//                           Tpg Start

int Create_TpgConfigStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTpgConfigStart.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TpgConfig(RunId);
}

//-------------------------------------------------------------------
//                          Tpg Stop

int Create_TpgConfigStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTpgConfigStop.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TpgConfig(RunId);
}

//-------------------------------------------------------------------
//                        Tpg Config File

int Create_TpgConfig(string RunId) {

    cout << "Source: SerenityTpg\n";
    cout << "BoardId: " << get_BoardId() << "\n";
    cout << "Timestamp: " << time(nullptr) << "\n";
    cout << "TpgControl:\n";
    cout << "  SelfTriggerDelay: " << get_SelfTriggerDelay() << "\n";
    cout << "  NumberOfLpGbtPairs: " << get_NumberOfLpGbtPairs() << "\n";
    cout << "  LpGbtPair:\n";

    for (int i = 0; i < get_NumberOfLpGbtPairs(); ++i) {
        cout << "    - UnpackerBlock:\n";
        cout << "      BxLatency: " << get_BxLatency(i) << "\n";
        cout << "      Stc4AUnpackerDelay: " << get_Stc4AUnpackerDelay(i) << "\n";
        cout << "      Stc16UnpackerDelay: " << get_Stc16UnpackerDelay(i) << "\n";
        cout << "      NumberOfUnpackers: " << get_NumberOfUnpackers(i) << "\n";
        cout << "      Unpackers:\n";
        for (int j = 0; j < get_NumberOfUnpackers(i); ++j) {
            cout << "        - Type: " << get_UnpackerType(i, j) << "\n";
        }
        cout << "      SelfTrigger:\n";
        cout << "        NumberOfEconts: " << get_NumberOfEconts(i) << "\n";
        cout << "        Econt:\n";
        for (int j = 0; j < get_NumberOfEconts(i); ++j) {
            cout << "          - EcontThreshold: " << get_EcontThreshold(i, j) << "\n";
            cout << "            TcEnableBits: " << get_TcEnableBits(i, j) << "\n";
            cout << "            EcontEnable: " << get_EcontEnable(i, j) << "\n";
        }
    }

    cout << "  TpgReadout:\n";
    cout << "    BackpressureDisable: " << get_BackpressureDisable() << "\n";
    cout << "    NumberOfChannels: " << get_NumberOfChannels() << "\n";
    cout << "    Channel:\n";
    for (int i = 0; i < get_NumberOfChannels(); ++i) {
        cout << "      - Latency: " << get_ChannelLatency(i) << "\n";
        cout << "        TmuxId: " << get_TmuxId(i) << "\n";
        cout << "        ReadoutWindow: " << get_ReadoutWindow(i) << "\n";
        cout << "        WordsPerBx: " << get_WordsPerBx(i) << "\n";
        cout << "        Masked: " << get_Masked(i) << "\n";
    }

    cout << "  TpgFastControl:\n";
    cout << "    L1aStretch: " << get_L1aStretch() << "\n";
    cout << "    SlinkFifoOffset: " << get_SlinkFifoOffset() << "\n";
    cout << "    EnableSlinkFifoThrottle: " << get_EnableSlinkFifoThrottle() << "\n";

    return EXIT_SUCCESS;
}


/*-------------------------------------------------------------------
                             Tpg Status
 -------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                           Tpg Start

int Create_TpgStatusStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTpgStatusStart.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TpgStatus(RunId);
}

//-------------------------------------------------------------------
//                          Tpg Stop

int Create_TpgStatusStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityTpgStatusStop.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_TpgStatus(RunId);
}

//-------------------------------------------------------------------
//                      Tpg status File

int Create_TpgStatus(string RunId) {

    cout << "Source: SerenityTpg\n";
    cout << "BoardId: " << get_BoardId() << "\n";
    cout << "Timestamp: " << time(nullptr) << "\n";
    cout << "TpgControl:\n";
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

    cout << "  TpgReadout:\n";
    cout << "    SlinkBackpressureLatch: " << get_SlinkBackpressureLatch() << "\n";
    cout << "    PacketCount: " << get_PacketCount() << "\n";
    cout << "    NumberOfChannels: " << get_NumberOfChannels() << "\n";
    cout << "    Channel:\n";
    for (int i = 0; i < get_NumberOfChannels(); ++i) {
        cout << "      - EventBufferMaxOccupancy: " << get_EventBufferMaxOccupancy(i) << "\n";
        cout << "        EventBufferOverflow: " << get_EventBufferOverflow(i) << "\n";
        cout << "        AddressBufferOverflow: " << get_AddressBufferOverflow(i) << "\n";
    }

    cout << "  TpgFastControl:\n";
    cout << "    EventCounter: " << get_EventCounter() << "\n";
    cout << "    OrbitCounter: " << get_OrbitCounter() << "\n";
    cout << "    SlinkFifoMaxOccupancy: " << get_SlinkFifoMaxOccupancy() << "\n";
    cout << "    SlinkFifoFullRisingEdgeCounter: " << get_SlinkFifoFullRisingEdgeCounter() << "\n";
    cout << "    SlinkFifoWriteEnableCounter: " << get_SlinkFifoWriteEnableCounter() << "\n";
    cout << "    SlinkFifoReadEnableCounter: " << get_SlinkFifoReadEnableCounter() << "\n";

    return EXIT_SUCCESS;
}