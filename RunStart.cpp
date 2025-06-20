#include "RunStart/DaqConfig.cpp"
#include <iostream>
#include <ctime>

using namespace std;

int timestamp = time(nullptr);
string RunId = "Run" + to_string(timestamp); //Create RunId with current timestamp


int main() {
    cout << "Starting DAQ Configuration for Run ID: " << RunId << endl;
    Create_DaqConfigStart(RunId);
    return 1;
}