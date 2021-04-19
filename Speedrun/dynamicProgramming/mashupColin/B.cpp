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

    pair<int, int> dp[n + 2];
    //returns pair(num of substrings, valid letters running count) state 1: n

    dp[0] = make_pair(0, 0);
    for (int i = 0; i <= n; i++)
    {
        if (c.find(s[i]) == c.end())
            dp[i + 1] = make_pair(dp[i].first, 0);
        else
            dp[i + 1] = make_pair(dp[i].first + dp[i].second + 1, dp[i].second + 1);
    }

    cout << dp[n].first;
}

int32_t main()
{
    solveCase();
}