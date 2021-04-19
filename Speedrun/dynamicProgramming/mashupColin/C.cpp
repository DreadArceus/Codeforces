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
    int dp[1 << 3];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 7; i++)
    {
        if (dp[i] == 0)
            dp[i] = INT32_MAX;
        for (int j = 0; j < n; j++)
            if (dp[i] > juices[j].first && juices[j].second == i)
                dp[i] = juices[j].first;
        for (int j = i + 1; j < 1 << 3; j++)
            if (j & i && (j | i) == j)
                dp[j] += dp[i];
    }
    dp[7] = min(min(min(dp[3] + dp[4], dp[2] + dp[5]), min(dp[1] + dp[6], dp[7])),
                min(min(dp[3] + dp[5], dp[3] + dp[6]),
                    min(dp[1] + dp[2] + dp[4], dp[5] + dp[6])));
    if (dp[7] > 300000)
        cout << -1;
    else
        cout << dp[7];
}

int32_t main()
{
    solveCase();
}