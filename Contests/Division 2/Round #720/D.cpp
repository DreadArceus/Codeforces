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

vector<set<int>> tree;
vector<bool> visited;

int dfs(int source)
{
    visited[source] = true;
    int leaf = source;
    for (auto x : tree[source])
    {
        if (!visited[x])
            leaf = dfs(x);
    }
    return leaf;
}

pii getBamboo(int source)
{
    visited[source] = true;
    pii reach = make_pair(source, source);
    if (tree[source].size() == 0)
        return reach;
    auto x = tree[source].begin();
    if (!visited[*x])
    {
        int leaf = dfs(*x);
        reach.second = leaf;
    }
    if (tree[source].size() == 1)
        return reach;
    x++;
    if (!visited[*x])
    {
        int leaf = dfs(*x);
        reach.first = leaf;
    }
    return reach;
}

void solveCase()
{
    int n = 0;
    cin >> n;
    tree = vector<set<int>>(n);
    visited = vector<bool>(n, false);
    for (int i = 0; i < n - 1; i++)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        tree[a - 1].insert(b - 1);
        tree[b - 1].insert(a - 1);
    }

    vector<pii> rem, add;
    vector<int> todo;

    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            if (tree[i].size() <= 2)
                continue;
            int cnt = 0;
            for (int x : tree[i])
                cnt += tree[x].size() > 2;
            if (cnt <= tree[i].size() - 2)
                todo.push_back(i);
        }
        if(todo.size() == 0) break;
        for (int i : todo)
        {
            int need = tree[i].size() - 2;
            vector<int> toRemove;
            for (auto x : tree[i])
            {
                if (need <= 0)
                    break;
                if (tree[x].size() > 2)
                {
                    tree[x].erase(i);
                    toRemove.push_back(x);
                    need--;
                    rem.push_back(make_pair(i, x));
                }
            }
            for (auto x : toRemove)
                tree[i].erase(x);
            toRemove.clear();
            for (auto x : tree[i])
            {
                if (need <= 0)
                    break;
                tree[x].erase(i);
                toRemove.push_back(x);
                need--;
                rem.push_back(make_pair(i, x));
            }
            for (auto x : toRemove)
                tree[i].erase(x);
        }
        todo.clear();
    }

    int lastLeaf = -1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        pii bamboo = getBamboo(i);
        if (lastLeaf != -1)
            add.push_back(make_pair(lastLeaf, bamboo.first));
        lastLeaf = bamboo.second;
    }

    cout << rem.size() << "\n";
    for (int i = 0; i < rem.size(); i++)
    {
        cout << rem[i].first + 1 << " " << rem[i].second + 1 << " "
             << add[i].first + 1 << " " << add[i].second + 1 << "\n";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}