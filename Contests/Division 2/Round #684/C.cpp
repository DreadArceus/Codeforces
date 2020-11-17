#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, m = 0;
        cin >> n >> m;
        vector<vector<int>> bGrid(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> bGrid[i][j];
            }
        }
        int op = 0;
        vector<vector<int>> operations;
        
        cout << op << "\n";
        for(auto x : operations)
        {
            for(auto y : x)
            {
                cout << y << " ";
            }
            cout << "\n";
        }
    }
}