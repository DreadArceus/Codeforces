#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int m = 0, n = 0;
    cin >> m >> n;
    vector<vector<int> > grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    int dp[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else if (j == 0)
                dp[i][j] = grid[i][j] + dp[i - 1][j];
            else if (i == 0)
                dp[i][j] = grid[i][j] + dp[i][j - 1];
            else
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[m-1][n-1];
}