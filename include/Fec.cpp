#include <fstream>
#include <iostream>

using namespace std;

/*-------------------------------------------------------------------
                            Fec Config
-------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                      Fec Config File

int Create_FecConfig(string RunId) {

    cout << "Source: SerenityFec\n";
    cout << "BoardId: " << get_BoardId() << "\n";
    cout << "Timestamp: " << time(nullptr) << "\n";

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                          Fec Start

int Create_FecConfigStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityDaqConfigStart.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_FecConfig(RunId);
}

//-------------------------------------------------------------------
//                          Fec Stop

int Create_FecConfigStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityFecConfigStop.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_FecConfig(RunId);
}


/*-------------------------------------------------------------------
                            Fec Status
-------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                      Fec Status File

int Create_FecStatus(string RunId) {

    cout << "Source: SerenityFec\n";
    cout << "BoardId: " << get_BoardId() << "\n";
    cout << "Timestamp: " << time(nullptr) << "\n";

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                          Fec Start

int Create_FecStatusStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityDaqStatusStart.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_FecStatus(RunId);
}

//-------------------------------------------------------------------
//                          Fec Stop

int Create_FecStatusStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityFecStatusStop.yaml";
    ofstream cout(filename.c_str());

    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_FecStatus(RunId);
}