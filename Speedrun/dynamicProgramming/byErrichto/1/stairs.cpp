#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    int dp[n+1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    cout << dp[n];
}