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
    int n = 0, k = 0;
    string s;
    cin >> n >> k >> s;
    set<char> c;
    for (int i = 0; i < k; i++)
    {
        char x;
        cin >> x;
        c.insert(x);
    }

    int dp[n + 2];
    //returns valid letters running count, state 1: n

    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        if (c.find(s[i]) == c.end())
            dp[i + 1] = 0;
        else
            dp[i + 1] = dp[i] + 1;
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += dp[i];
    }
    cout << ans;
}

int32_t main()
{
    solveCase();
}