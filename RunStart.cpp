#include <sys/stat.h>
#include <sys/types.h>
#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include "include/Daq.cpp"
#include "include/Fec.cpp"
#include "include/Framer.cpp"
#include "include/Slink.cpp"
#include "include/Tpg.cpp"
#include "include/Trg.cpp"

using namespace std;

int timestamp = time(nullptr);
string RunId = "Run" + to_string(timestamp); //Create RunId with current timestamp


int main() {

    cout << "Creating Run Files: " << RunId << "\n" << endl;

    if (mkdir(RunId.c_str(), 0777) == -1){
        cerr << "Error :  " << strerror(errno) << endl;
    }
    else
        cout << "Directory created" << endl;

    cout << "Start phase.... \n" << endl;
    
    cout << "\n\nStarting DAQ Configuration" << endl;
    Create_DaqConfigStart(RunId);
    cout << "DAQ Configuration created successfully\n" << endl;

    cout << "Starting DAQ Status" << endl;
    Create_DaqStatusStart(RunId);
    cout << "DAQ Status created successfully\n" << endl;

    cout << "Starting Fec Configuration" << endl;
    Create_FecConfigStart(RunId);
    cout << "Fec Configuration created successfully\n" << endl;

    cout << "Starting Fec Status" << endl;
    Create_FecStatusStart(RunId);
    cout << "Fec Status created successfully\n" << endl;

    cout << "Starting Framer Configuration" << endl;
    Create_FramerConfigStart(RunId);
    cout << "Framer Configuration created successfully\n" << endl;

    cout << "Starting Slink Configuration" << endl;
    Create_SlinkConfigStart(RunId);
    cout << "Slink Configuration created successfully\n" << endl;

    cout << "Starting Tpg Configuration" << endl;
    Create_TpgConfigStart(RunId);
    cout << "Tpg Configuration created successfully\n" << endl;

    cout << "Starting Tpg Status" << endl;
    Create_TpgStatusStart(RunId);
    cout << "Tpg Status created successfully\n" << endl;

    cout << "Starting Trg Configuration" << endl;
    Create_TrgConfigStart(RunId);
    cout << "Trg Configuration created successfully\n" << endl;

    cout << "Starting Trg Status" << endl;
    Create_TrgStatusStart(RunId);
    cout << "Trg Status created successfully" << endl;


    cout << "Stop phase.... \n" << endl;
    
    cout << "\n\nStarting DAQ Configuration" << endl;
    Create_DaqConfigStop(RunId);
    cout << "DAQ Configuration created successfully\n" << endl;

    cout << "Starting DAQ Status" << endl;
    Create_DaqStatusStop(RunId);
    cout << "DAQ Status created successfully\n" << endl;

    cout << "Starting Fec Configuration" << endl;
    Create_FecConfigStop(RunId);
    cout << "Fec Configuration created successfully\n" << endl;

    cout << "Starting Fec Status" << endl;
    Create_FecStatusStop(RunId);
    cout << "Fec Status created successfully\n" << endl;

    cout << "Starting Framer Configuration" << endl;
    Create_FramerConfigStop(RunId);
    cout << "Framer Configuration created successfully\n" << endl;

    cout << "Starting Slink Configuration" << endl;
    Create_SlinkConfigStop(RunId);
    cout << "Slink Configuration created successfully\n" << endl;

    cout << "Starting Tpg Configuration" << endl;
    Create_TpgConfigStop(RunId);
    cout << "Tpg Configuration created successfully\n" << endl;

    cout << "Starting Tpg Status" << endl;
    Create_TpgStatusStop(RunId);
    cout << "Tpg Status created successfully\n" << endl;

    cout << "Starting Trg Configuration" << endl;
    Create_TrgConfigStop(RunId);
    cout << "Trg Configuration created successfully\n" << endl;

    cout << "Starting Trg Status" << endl;
    Create_TrgStatusStop(RunId);
    cout << "Trg Status created successfully" << endl;



    cout << "\n\nRun files created successfully!" << endl;

    return 1;
}