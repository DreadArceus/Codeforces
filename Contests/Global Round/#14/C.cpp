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
    int n = 0, m = 0, x = 0;
    cin >> n >> m >> x;
    vector<pii> h(n, make_pair(0, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> h[i].first;
        h[i].second = i;
    }
    sort(h.begin(), h.end());
    int maxDistri = n / m;
    vector<int> ans(n);
    vector<pii> sum(m + 1, make_pair(0, -1));
    for (int i = 1; i <= m; i++)
        sum[i].second = i;
    int cur = 0, stNum = 1, count = 0;
    while (cur != n && stNum != m + 1)
    {
        if (count >= maxDistri)
        {
            count = 0;
            stNum++;
            continue;
        }
        sum[stNum].first += h[cur].first;
        ans[h[cur].second] = stNum;
        cur++;
        count++;
    }
    if (stNum == m + 1)
    {
        while (cur != n)
        {
            sort(sum.begin(), sum.end());
            for (int i = 0; i < sum.size() && cur != n; i++)
            {
                if (sum[i].second == -1)
                    continue;
                sum[i].first += h[cur].first;
                ans[h[cur].second] = sum[i].second;
                cur++;
            }
        }
    }
    cout << "YES\n";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}