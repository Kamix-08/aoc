#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#include "d5.cpp"

using namespace std;

unordered_map<int, unordered_set<int>> befores;

bool in(int a, unordered_set<int> b)
{
    return b.find(a) != b.end();
}

bool checkLine(vector<int>& line)
{
    for (int i=0; i<line.size(); i++)
        for (int j=i+1; j<line.size(); j++)
            if(in(line[j], befores[line[i]]))
                return false;
    return true;
}

int main() {
    vector<pair<int, int>> ins;
    vector<vector<int>> upd;

    tie(ins, upd) = readData();

    for (auto& p : ins) 
    {
        if(befores.find(p.second) != befores.end())
            befores[p.second].emplace(p.first);
        else
            befores[p.second] = unordered_set<int>{p.first};
    }

    int sum[2] = {0, 0};
    for (auto& line : upd)
    {
        bool fine = checkLine(line);

        if(!fine)
            sort(line.begin(), line.end(), [](int a, int b){ return in(a, befores[b]); });

        sum[1 - fine] += line[line.size() / 2];
    }

    cout << sum[0] << '\n' << sum[1] << '\n';

    return 0;
}