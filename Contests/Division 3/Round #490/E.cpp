#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
#define pii pair<int, int>

bool rev(pii a, pii b)
{
    return a.first > b.first;
}

vector<vector<int>> graph;
vector<bool> vis1, vis2;

void dfs_real(int source)
{
    vis1[source] = true;
    for (auto i : graph[source])
    {
        if (!vis1[i])
            dfs_real(i);
    }
}

int dfs_count(int source)
{
    vis2[source] = true;
    int cnt = 1;
    for (auto i : graph[source])
    {
        if (!vis2[i])
            cnt += dfs_count(i);
    }
    return cnt;
}

void solveCase()
{
    int n = 0, m = 0, s = 0;
    cin >> n >> m >> s;
    graph.resize(n);
    vis1.resize(n, false);
    while (m--)
    {
        int u = 0, v = 0;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
    }
    dfs_real(s - 1);
    vector<pii> counts;
    for (int i = 0; i < n; i++)
    {
        if (vis1[i])
            continue;
        vis2.clear();
        vis2.resize(n, false);
        counts.push_back(make_pair(dfs_count(i), i));
    }
    sort(counts.begin(), counts.end(), rev);
    int connected = 1;
    for (auto c : counts)
    {
        if (vis1[c.second])
            continue;
        connected++;
        dfs_real(c.second);
    }
    cout << connected - 1 << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solveCase();
}