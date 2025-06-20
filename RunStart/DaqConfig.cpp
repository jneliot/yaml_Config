#include <fstream>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::fstream;
using std::ofstream;
using std::string;

int Create_DaqConfigStart(string RunId) {
    string filename = RunId + "_SerenityDaqConfigurationStart.yaml";



    string text("output3.txt");
    FILE *o_file = fopen(filename.c_str(), "w+");
    if (o_file) {
        fwrite(text.c_str(), 1, text.size(), o_file);
        cerr << "Done Writing!" << endl;
    }

    return EXIT_SUCCESS;
}