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
    vector<pii> juices(n);
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        string vit;
        cin >> c >> vit;
        int mask = 0;
        for (int j = 0; j < vit.length(); j++)
        {
            if (vit[j] == 'A')
                mask += 4;
            if (vit[j] == 'B')
                mask += 2;
            if (vit[j] == 'C')
                mask += 1;
        }
        juices[i] = make_pair(c, mask);
    }

    int dp[8]; //returns min cost, state 1: bitmask of vitamins
    dp[0] = 0;
    for (int i = 1; i < 8; i++)
        dp[i] = INT32_MAX;

    for (int i = 1; i < 8; i++)
    {
        for (auto juice : juices)
        {
            if ((juice.second & i) == 0)
                continue;
            dp[i] = min(dp[i], dp[i - (juice.second & i)] + juice.first);
        }
    }

    if (dp[7] == INT32_MAX)
        cout << -1;
    else
        cout << dp[7];
}

int32_t main()
{
    solveCase();
}