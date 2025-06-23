#ifndef TPG_HPP
#define TPG_HPP

using namespace std;

int get_SelfTriggerDelay() {
    return 407;
}

int get_BxLatency(int index) {
    return 0;
}

int get_Stc4AUnpackerDelay(int index) {
    return 3;
}

int get_Stc16UnpackerDelay(int index) {
    return 3;
}

int get_NumberOfUnpackers(int index) {
    return index == 0 ? 4 : 6;
}

int get_UnpackerType(int lpGbtIndex, int unpackerIndex) {
    if (lpGbtIndex == 0) {
        return 1;
    } else {
        static const int types[] = {0, 0, 0, 2, 2, 2};
        return types[unpackerIndex];
    }
}

int get_NumberOfEconts(int index) {
    return 6;
}

int get_EcontThreshold(int lpGbtIndex, int econtIndex) {
    return 511;
}

int get_TcEnableBits(int lpGbtIndex, int econtIndex) {
    return 16383;
}

int get_EcontEnable(int lpGbtIndex, int econtIndex) {
    return 0;
}

int get_BackpressureDisable() {
    return 0;
}

int get_NumberOfChannels() {
    return 14;
}

int get_ChannelLatency(int channelIndex) {
    static const int latencies[] = {11, 1617, 1629, 1629, 1636, 3219, 3217, 3217, 3225, 2985, 3200, 3200, 3200, 3200};
    return latencies[channelIndex];
}

int get_TmuxId(int channelIndex) {
    return 0;
}

int get_ReadoutWindow(int channelIndex) {
    if (channelIndex == 0) {
        return 0;
    } else {
        return 3;
    }
}

int get_WordsPerBx(int channelIndex) {
    static const int wordsPerBx[] = {8, 4, 4, 4, 4, 8, 8, 8, 8, 7, 8, 8, 8, 8};
    return wordsPerBx[channelIndex];
}

int get_Masked(int channelIndex) {
    return 0;
}
int get_Locked(int lpGbtIndex, int counterIndex) {
    return 0;
}

int get_ValidPacket(int lpGbtIndex, int counterIndex) {
    return 0;
}

int get_Bc0Packet(int lpGbtIndex, int counterIndex) {
    return 0;
}

int get_TriggerCounter(int lpGbtIndex) {
    return 0;
}

int get_SlinkBackpressureLatch() {
    return 0;
}

int get_PacketCount() {
    return 0;
}

int get_EventBufferMaxOccupancy(int channelIndex) {
    return 0;
}

int get_EventBufferOverflow(int channelIndex) {
    return 0;
}

int get_AddressBufferOverflow(int channelIndex) {
    return 0;
}

int get_EventCounter() {
    return 0;
}

#endif // TPG_HPP