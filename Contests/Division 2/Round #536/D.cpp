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

vector<set<int>> graph;
vector<int> visited, ans;
set<int> options;

void unqTraverse(int source)
{
    options.insert(source);
    while (options.size() != 0)
    {
        auto x = options.begin();
        visited[*x] = true;
        ans.push_back(*x);
        for (auto y : graph[*x])
        {
            if (!visited[y])
                options.insert(y);
        }
        options.erase(x);
    }
}

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m;
    graph.resize(n);
    visited.resize(n);
    while (m--)
    {
        int u = 0, v = 0;
        cin >> u >> v;
        u--;
        v--;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    unqTraverse(0);
    for (auto i : ans)
        cout << i + 1 << " ";
}

int32_t main()
{
    solveCase();
}