#include <iostream>
#include <queue>
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
    vector<int> h(n);
    priority_queue<pii> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        pq.push(make_pair(h[i], i));
    }
    vector<int> ans(n), sums(n, 0);
    int i = 1;
    bool f = true;
    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        ans[cur.second] = i;
        sums[cur.second] += cur.first;
        if (f)
            i++;
        else
            i--;
        if (i == m + 1)
        {
            i = m;
            f = !f;
        }
        if (i == 0)
        {
            i = 1;
            f = !f;
        }
    }
    int maxH = 0, minH = INT32_MAX;
    for (int sum : sums)
    {
        maxH = max(maxH, sum);
        minH = min(minH, sum);
    }
    if(maxH - minH > x)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}