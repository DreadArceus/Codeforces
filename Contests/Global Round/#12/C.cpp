#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        vector<string> grid(n);
        for(int i = 0; i < n; i++)
        {
            cin >> grid[i];
        }
        int cPos = -2;
        for(int i = 0; i < n; i++)
        {
            string cur = "";
            cur.push_back(grid[i][0]);
            cur.push_back(grid[i][1]);
            for(int j = 2; j < n; j++)
            {
                cur.push_back(grid[i][j]);
                if(cur == "XXX")
                {
                    grid[i][j + cPos] = 'O';
                }
                cur.erase(cur.begin());
            }
            cPos++;
            if(cPos > 0)
            {
                cPos = -2;
            }
        }
        cPos = -2;
        for(int i = 0; i < n; i++)
        {
            string cur = "";
            cur.push_back(grid[0][i]);
            cur.push_back(grid[1][i]);
            for(int j = 2; j < n; j++)
            {
                cur.push_back(grid[j][i]);
                if(cur == "XXX")
                {
                    grid[j + cPos][i] = 'O';
                }
                cur.erase(cur.begin());
            }
            cPos++;
            if(cPos > 0)
            {
                cPos = -2;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << (grid[i][j]) << " ";
            }
            cout << "\n";
        }
    }
}