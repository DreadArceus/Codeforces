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

vector<vector<int>> graph;
vector<bool> visited;
vector<int> sorted;

void dfs(int source)
{
    visited[source] = true;
    for (auto i : graph[source])
    {
        if (!visited[i])
            dfs(i);
    }
    sorted.push_back(source);
}

void topologicalSort()
{
    visited.resize(graph.size(), false);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(sorted.begin(), sorted.end());
}

void solveCase()
{
    int n = 0, m = 0, s = 0;
    cin >> n >> m >> s;
    graph.resize(n);
    while (m--)
    {
        int u = 0, v = 0;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
    }
    topologicalSort();
    visited.clear();
    visited.resize(n, false);
    dfs(s - 1);
    int connected = 1;
    for (auto i : sorted)
    {
        if (visited[i])
            continue;
        dfs(i);
        connected++;
    }
    cout << connected - 1 << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solveCase();
}