#include <iostream>
#include <queue>
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

vector<vector<int>> grid;
vector<vector<int>> graph;
int w = 0;

vector<int> bfs(int source)
{
    int n = graph.size();
    vector<int> d(n, INT64_MAX);

    d[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int minI = q.front();
        q.pop();
        for (auto x : graph[minI])
        {
            if (d[x] > d[minI] + w)
            {
                d[x] = d[minI] + w;
                q.push(x);
            }
        }
    }
    return d;
}

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m >> w;
    grid = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    graph.resize(n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == -1)
                continue;
            if (j != m - 1 && grid[i][j + 1] != -1)
                graph[i * m + j].push_back(i * m + j + 1);
            if (j != 0 && grid[i][j - 1] != -1)
                graph[i * m + j].push_back(i * m + j - 1);
            if (i != n - 1 && grid[i + 1][j] != -1)
                graph[i * m + j].push_back((i + 1) * m + j);
            if (i != 0 && grid[i - 1][j] != -1)
                graph[i * m + j].push_back((i - 1) * m + j);
        }
    }
    vector<int> dist1 = bfs(0);
    vector<int> dist2 = bfs(n * m - 1);
    int bestPortal1 = INT64_MAX, bestPortal2 = INT64_MAX;
    for (int i = 0; i < dist1.size(); i++)
    {
        if (dist1[i] == INT64_MAX)
            continue;
        int x = i / m, y = i % m;
        if (grid[x][y] == 0)
            continue;
        bestPortal1 = min(dist1[i] + grid[x][y], bestPortal1);
    }
    for (int i = 0; i < dist2.size(); i++)
    {
        if (dist2[i] == INT64_MAX)
            continue;
        int x = i / m, y = i % m;
        if (grid[x][y] == 0)
            continue;
        bestPortal2 = min(dist2[i] + grid[x][y], bestPortal2);
    }
    int bestPath = 0;
    if (bestPortal1 == INT64_MAX || bestPortal2 == INT64_MAX)
        bestPath = dist2[0];
    else
        bestPath = min(bestPortal1 + bestPortal2, dist2[0]);
    cout << (bestPath == INT64_MAX ? -1 : bestPath);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solveCase();
}