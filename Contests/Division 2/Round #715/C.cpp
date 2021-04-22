#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define int long long
#define pii pair<int, int>

void solveCase()
{
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int dp[n][n];
    //returns sum of d, state 1: index of max, state 2: index of min
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j >= 0; j--)
        {
            if (i - j <= 1)
                dp[i][j] = v[i] - v[j];
            else
                dp[i][j] = v[i] - v[j] + min(dp[i - 1][j], dp[i][j + 1]);
        }
    }
    cout << dp[n - 1][0];
}

int32_t main()
{
    solveCase();
}