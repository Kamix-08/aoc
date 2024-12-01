#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <iostream>

#define ull unsigned long long

using namespace std;

tuple<vector<int>, vector<int>> read_data()
{
    vector<int> d1, d2;
    d1.reserve(1000);
    d2.reserve(1000);
    
    ifstream input("./d1.in");
    string line;

    while(getline(input, line))
    {
        d1.emplace_back(stoi(line.substr(0, 5)));
        d2.emplace_back(stoi(line.substr(8)));
    }

    return make_tuple(d1, d2);
}