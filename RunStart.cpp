#include <sys/stat.h>
#include <sys/types.h>
#include <bits/stdc++.h>
#include "include/DaqConfig.cpp"
#include "include/DaqStatus.cpp"
#include "include/FecConfig.cpp"
#include "include/FecStatus.cpp"
#include <iostream>
#include <ctime>

using namespace std;

int timestamp = time(nullptr);
string RunId = "Run" + to_string(timestamp); //Create RunId with current timestamp


int main() {

    cout << "Creating Run Files: " << RunId << endl;

    if (mkdir(RunId.c_str(), 0777) == -1){
        cerr << "Error :  " << strerror(errno) << endl;
    }
    else
        cout << "Directory created" << endl;
    
    cout << "Starting DAQ Configuration" << endl;
    Create_DaqConfigStart(RunId);
    cout << "DAQ Configuration created successfully" << endl;

    cout << "Starting DAQ Status" << endl;
    Create_DaqStatusStart(RunId);
    cout << "DAQ Status created successfully" << endl;

    cout << "Starting Fec Configuration" << endl;
    Create_FecConfigStart(RunId);
    cout << "Fec Configuration created successfully" << endl;

    cout << "Starting Fec Status" << endl;
    Create_FecStatusStart(RunId);
    cout << "Fec Status created successfully" << endl;

    

    return 1;
}