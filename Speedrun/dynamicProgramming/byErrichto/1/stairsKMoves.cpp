#include <iostream>
using namespace std;
int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    int dp[n+1][k];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[1][k - 1] = 1;
    dp[2][k - 1] = 1;
    if (k > 1)
        dp[2][k - 2] = 1;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j < k; j++)
        {
            dp[i][j - 1] = dp[i - 1][j] + dp[i - 2][j];
        }
    }
    int ans = 0;
    for (int j = 0; j < k; j++)
    {
        ans += dp[n][j];
    }
    cout << ans;
}