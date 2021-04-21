#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
#define pii pair<int, int>

vector<int> graph;
vector<int> reversedGraph;

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m;
    graph.resize(n, -1);
    reversedGraph.resize(n, -1);
    while (m--)
    {
        int u = 0, v = 0;
        cin >> u >> v;
        graph[u - 1] = v - 1;
        reversedGraph[v - 1] = u - 1;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if(reversedGraph[i] != -1) continue;
        int curr = i;
        while(curr != -1)
        {
            ans.push_back(curr);
            curr = graph[curr];
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto i : ans)
    {
        cout << i + 1 << " ";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solveCase();
}