#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const int n = 140;
const string pattern = "XMAS";

vector<string> readData() 
{
    ifstream input("./d4.in");

    vector<string> data(n);
    for(string& c : data) 
        c.reserve(n);

    for(int i=0; i<n; i++)
        getline(input, data[i]);

    return data;
}