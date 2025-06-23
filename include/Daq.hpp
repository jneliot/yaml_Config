#ifndef DAQ_HPP
#define DAQ_HPP

#include <iostream>
#include <string>

using namespace std;

string get_BoardId() {
    return "SerenityU";
}

int get_Version() {
    return 2; 
}

int get_NumberOfSLinks() {
    return 1; 
}

int* get_Channel(int slink_idx = 0) {
    static int channels[] = {1, 1};
    return channels;
}

int get_NumberOfLpGbtPairs() {
    return 3; 
}

int get_EcondHeaderPattern(int lpgbtPair_idx = 0) {
    return 340; 
}

int get_DisableBackpressure(int lpgbtPair_idx = 0) {
    return 0; 
}

int get_AllowBxMismatch(int lpgbtPair_idx = 0) {
    return 1; 
}

int get_NumberOfEconds(int lpgbtPair_idx = 0) {
    // Placeholder for actual number of Econds retrieval logic
    return 0; 
}

int* get_Econd_addresses(int lpgbtPair_idx = 0, int econd_idx = 0) {
    static int addresses[2] = {16383, 16383};
    return addresses;
}

int get_Econd_Id(int econd_idx = 0, int lpgbtPair_idx = 0) {
    return 15; 
}

int get_CalPulseType(int lpgbtPair_idx = 0, int stream_idx = 0) {
    return 1; 
}

int get_LoopUserCommand(int lpgbtPair_idx = 0, int stream_idx = 0) {
    return 0; 
}

int get_LinkResetCommand(int lpgbtPair_idx = 0, int stream_idx = 0) {
    return 0; 
}

int get_ForceLock(int lpgbtPair_idx = 0) {
    return 0; 
}

int get_PreL1aOffset(int lpgbtPair_idx = 0) {
    return 2; 
}

int get_BcrResetValue() {
    return 1; 
}

int get_OcrResetValue() {
    return 0; 
}

int get_TimeoutLimit() {
    return 8000; 
}

int get_EcondIdlePattern() {
    return 13421823; 
}

int get_L1aStretch() {
    return 0; 
}

int get_SlinkFifoOffset() {
    return 0; 
}

int get_EnableSlinkFifoThrottle() {
    return 1; 
}

int get_L1aEcrEnable() {
    return 0; 
}

int get_OcrEnable() {
    return 0; 
}

int get_OcrPeriod() {
    return 8; 
}

int get_PreL1aOffsetOverride3() {
    return 0; 
}

int get_PreL1aOffsetOverride3Enable() {
    return 3; 
}

int get_CalPulseIntDelay() {
    return 8; 
}

int get_CalPulseExtDelay() {
    return 10; 
}

int get_HeaderCounter(int index) {
    return 0;
}

int get_TrailerCounter(int index) {
    return 0;
}

int get_EventCounter(int index) {
    return 0;
}

int get_LatchedIdleError(int i, int j) {
    return 0;
}

int get_NumberOfCrcErrors(int i, int j) {
    return 0;
}

string get_IntegratedStatus() {
    return "None";
}

int get_OrbitCounter() {
    return 4;
}

int get_SlinkFifoMaxOccupancy() {
    return 2;
}

int get_SlinkFifoFullRisingEdgeCounter() {
    return 0;
}

int get_SlinkFifoWriteEnableCounter() {
    return 0;
}

int get_SlinkFifoReadEnableCounter() {
    return 0;
}

#endif // DAQ_HPP