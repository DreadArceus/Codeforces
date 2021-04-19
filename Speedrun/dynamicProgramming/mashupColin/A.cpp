#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
#define pii pair<int, int>

void solveCase()
{
    int n = 0;
    cin >> n;
    int dp[61]; //returns number of ways to fit, state 1: n
    dp[1] = 0;
    dp[2] = 2;
    for (int i = 1; i <= n - 2; i++)
    {
        dp[i + 2] = dp[i] * 2;
    }
    cout << dp[n];
}

int32_t main()
{
    solveCase();
}