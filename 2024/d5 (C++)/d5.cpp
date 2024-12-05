#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

tuple<vector<pair<int, int>>, vector<vector<int>>> readData()
{
    ifstream file("./d5.in");

    bool mode = true;

    vector<pair<int, int>> ins;
    vector<vector<int>> upd;

    string line;
    while(getline(file, line))
    {
        if(line == "")
        {
            mode = false;
            continue;
        }

        if(mode)
        {
            ins.emplace_back(stoi(line.substr(0,2)), stoi(line.substr(3,2)));
            continue;
        }
        
        vector<int> u;
        for (int i=0; i<(line.size() + 1)/3; i++)
            u.push_back(stoi(line.substr(i * 3, 2)));

        upd.push_back(u);
    }

    return make_tuple(ins, upd);
}