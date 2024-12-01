#include <unordered_map>

#include "d1.cpp"

int main()
{   
    vector<int> d1, d2;

    tie(d1, d2) = read_data();

    unordered_map<int, int> count;

    for(int c : d2)
    {
        if(count.find(c) == count.end())
        {
            count[c] = 1;
            continue;
        }

        count[c]++;
    }

    ull sum = 0;

    for(int c : d1)
    {
        if(count.find(c) == count.end())
            continue;

        sum += c * count[c];
    }

    cout << sum;
    
    return 0;
}