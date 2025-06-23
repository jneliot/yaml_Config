#include <fstream>
#include <iostream>

using namespace std;

int Create_FecStatusStart(string RunId) {
    string filename = RunId + "/" + RunId + "_SerenityDFecStatusStart.yaml";

    ofstream cout(filename.c_str()); //Open the file for writing with cout
    if (!cout) {
        cerr << "Error opening file: " << filename << endl;
        return EXIT_FAILURE;
    }

    cout << "Source: SerenityFec\n";
    cout << "BoardId: " << get_BoardId() << "\n";
    cout << "Timestamp: " << time(nullptr) << "\n";

    return EXIT_SUCCESS;
}