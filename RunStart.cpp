#include <sys/stat.h>
#include <sys/types.h>
#include <bits/stdc++.h>
#include "RunStartFiles/DaqConfig.cpp"
#include <iostream>
#include <ctime>

using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::system;

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
    return 1;
}