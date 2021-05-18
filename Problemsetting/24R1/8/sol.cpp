#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t mod = 1e9 + 7;

struct Edge
{
    int u;
    int v;
    int w;
};

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<Edge> edges;
    vector<int> track_tree(n);
    for (int i = 0; i < n; i++)
        track_tree[i] = i;
    for (int i = 0; i < m; i++)
    {
        int u = 0, v = 0, w = 0;
        cin >> u >> v >> w;
        edges.push_back({u - 1, v - 1, w});
    }
    auto cmp = [](Edge a, Edge b)
    { return -1 * a.w < -1 * b.w; };
    sort(edges.begin(), edges.end(), cmp);
    int maxW = 1;
    for (auto e : edges)
    {
        if (track_tree[e.u] == track_tree[e.v])
            continue;
        maxW = (maxW * e.w) % mod;
        int oldTree = track_tree[e.u], newTree = track_tree[e.v];
        for (int i = 0; i < n; i++)
            if (track_tree[i] == oldTree)
                track_tree[i] = newTree;
    }
    cout << maxW;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solveCase();
}