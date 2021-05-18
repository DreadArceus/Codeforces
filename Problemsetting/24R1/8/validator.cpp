#include <vector>
#include <queue>
#include "testlib.h"

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void bfs(int source)
{
    visited[source] = true;
    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto y : graph[x])
        {
            if (!visited[y])
            {
                visited[y] = true;
                q.push(y);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000, "n");
    visited.resize(n);
    graph.resize(n);
    inf.readSpace();
    int m = inf.readInt(1, 1000000, "m");
    inf.readEoln();
    for (int i = 0; i < m; i++)
    {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readSpace();
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
        int w = inf.readInt(1, 1000, "w");
        inf.readEoln();
    }
    bfs(0);
    for (auto x : visited)
    {
        ensuref(x == true, "Disconnected graph");
    }
    inf.readEof();
}
