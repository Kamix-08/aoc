#include <utility>

#include "d4.cpp"

using namespace std;

vector<string> board;

char get_char(int y, int x)
{
    if(x < 0 || x >= n) return 0;
    if(y < 0 || y >= n) return 0;
    return board[y][x];
}

const pair<int, int> directions[] = {
    { 1, 0}, { 1, 1}, 
    { 0, 1}, {-1, 1}, 
    {-1, 0}, {-1,-1},
    { 0,-1}, { 1,-1}
};

int main() 
{
    board = readData(); 

    long long count = 0;

    for(int x=0; x<n; x++)
        for(int y=0; y<n; y++)
        {
            if(board[y][x] != pattern[0])
                continue;

            for(const auto& dir : directions)
            {
                bool match = true;

                for(int i=1; i<pattern.size(); i++)
                    if(get_char(y+i*dir.first, x+i*dir.second) != pattern[i])
                    {
                        match = false;
                        break;
                    }

                if(match)
                    ++count;
            }
        }

    cout << count << '\n';

    return 0;
}