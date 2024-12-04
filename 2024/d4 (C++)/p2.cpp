#include "d4.cpp"

using namespace std;

bool is_mas(char a, char b)
{
    if(b < a)
        swap(a, b);
    return (a == 'M' && b == 'S');
}

int main()
{
    vector<string> board = readData();

    long long count = 0;

    for(int y=1; y<n-1; y++)
        for(int x=1; x<n-1; x++)
        {
            if(board[y][x] != 'A')
                continue;

            if(is_mas(board[y-1][x-1], board[y+1][x+1]) && is_mas(board[y+1][x-1], board[y-1][x+1]))
                ++count;
        }

    cout << count << '\n';

    return 0;
}