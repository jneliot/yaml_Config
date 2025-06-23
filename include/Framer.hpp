#ifndef FRAMER_HPP
#define FRAMER_HPP

#include <vector>
#include <ctime>

using namespace std;

// Structure to represent an Elink
struct Elink {
    int Address;
    int Shift;
};

// Structure to represent a Link
struct Link {
    int LinkNumber;
    vector<Elink> Elinks;
};

vector<Link> get_LpGbtMGT() {
    vector<Link> links = {
        {48, {{6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}}},
        {49, {{6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}}},
        {50, {{6, 7}, {5, 9}, {4, 5}, {3, 0}, {2, 0}, {1, 0}, {0, 0}}},
        {51, {{6, 7}, {5, 8}, {4, 5}, {3, 0}, {2, 0}, {1, 0}, {0, 0}}},
        {57, {{2, 0}, {1, 0}, {0, 0}, {4, 0}, {3, 0}, {6, 0}, {5, 0}}},
        {58, {{2, 131}, {1, 131}, {0, 134}, {4, 134}, {3, 133}, {6, 133}, {5, 133}}},
        {59, {{2, 131}, {1, 131}, {0, 134}, {4, 134}, {3, 133}, {6, 133}, {5, 133}}}
    };
    return links;
}

#endif // FRAMER_HPP