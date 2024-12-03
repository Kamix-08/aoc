#include <algorithm>

#include "d1.cpp"

int main()
{  
    vector<int> d1, d2;

    tie(d1, d2) = read_data();

    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());

    ull sum = 0;

    for(int i=0; i<d1.size(); i++)
        sum += abs(d2[i] - d1[i]);

    cout << sum;
    
    return 0;
}