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
    int n = 0, maxAns = 0;
    cin >> n;
    vector<int> uni(n), skill(n);
    for (int i = 0; i < n; i++)
        cin >> uni[i];
    for (int i = 0; i < n; i++)
    {
        cin >> skill[i];
        maxAns += skill[i];
    }
    vector<vector<int>> ans(n + 1, vector<int>());
    for (int i = 0; i < n; i++)
        ans[uni[i]].push_back(skill[i]);
    for (int u = 1; u <= n; u++)
    {
        if (ans[u].size() == 0)
            continue;
        sort(ans[u].begin(), ans[u].end());
        for (int i = 1; i < ans[u].size(); i++)
            ans[u][i] += ans[u][i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        int a = maxAns;
        for (auto x : ans)
        {
            int rem = x.size() % i;
            if (rem == 0)
                continue;
            a -= x[rem - 1];
        }
        cout << a << " ";
    }
    cout << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}