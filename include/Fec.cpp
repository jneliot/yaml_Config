#include <fstream>
#include <iostream>

using namespace std;

/*-------------------------------------------------------------------
                            Fec Config
-------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                      Fec Config File

int Create_FecConfig(string RunId, ofstream& fileOut) {

    fileOut << "Source: SerenityFec\n";
    fileOut << "BoardId: " << get_BoardId() << "\n";
    fileOut << "Timestamp: " << time(nullptr) << "\n";

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                          Fec Start

int Create_FecConfigStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityDaqConfigStart.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_FecConfig(RunId, fileOut);
}

//-------------------------------------------------------------------
//                          Fec Stop

int Create_FecConfigStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityFecConfigStop.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_FecConfig(RunId, fileOut);
}


/*-------------------------------------------------------------------
                            Fec Status
-------------------------------------------------------------------*/

//-------------------------------------------------------------------
//                      Fec Status File

int Create_FecStatus(string RunId,  ofstream& fileOut) {

    fileOut << "Source: SerenityFec\n";
    fileOut << "BoardId: " << get_BoardId() << "\n";
    fileOut << "Timestamp: " << time(nullptr) << "\n";

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
//                          Fec Start

int Create_FecStatusStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityDaqStatusStart.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_FecStatus(RunId, fileOut);
}

//-------------------------------------------------------------------
//                          Fec Stop

int Create_FecStatusStop(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityFecStatusStop.yaml";
    ofstream fileOut(filename.c_str());

    if (!fileOut) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    return Create_FecStatus(RunId, fileOut);
}