//Recursion and even checking adjacent cells, was never needed.
//Just do a generalisation that makes everything adjacent, different.
//The following is basically like colouring the whole grid like a chessboard,
//  so all adjacent cells are even if the center is odd and vice-versa
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
        vector<vector<int>> v(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> v[i][j];
                if((i + j) % 2 == 0)
                {
                    if(v[i][j] % 2 != 0)
                    {
                        v[i][j]++;
                    }
                }
                else if(v[i][j] % 2 == 0)
                {
                    v[i][j]++;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
    }
}