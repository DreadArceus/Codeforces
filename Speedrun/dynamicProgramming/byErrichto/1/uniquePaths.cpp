#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int m = 0, n = 0;
    cin >> m >> n;
    int dp[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    cout << dp[m-1][n-1];
}