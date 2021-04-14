#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct TreeNode
{
    set<int> children;
    vector<pair<int, int> > choices;
    int parent;
    int val;
    int sum;
    int depth;
};

int main()
{
    int n = 0;
    cin >> n;
    vector<TreeNode> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = TreeNode();
        if (i == 0)
            v[i].depth = 1;
        if (i != 0)
        {
            int p = 0;
            cin >> p;
            v[p - 1].children.insert(i);
            v[i].parent = p - 1;
            v[i].depth = v[p - 1].depth + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].sum;
    }
    v[0].val = v[0].sum;

    for (int i = 0; i < n; i++)
    {
        if (v[i].children.size() != 0)
            continue;
        int j = i;
        if (v[i].sum == -1)
        {
            v[i].val = 0;
            j = v[i].parent;
        }
        while (j != 0)
        {
            int sumBelow = v[j].sum;
            int sumAbove = v[v[v[j].parent].parent].sum;
            int diff = sumBelow - sumAbove;
            if (diff < 0)
            {
                cout << -1;
                return 0;
            }
            v[v[j].parent].choices.push_back(make_pair(j, diff));
            j = v[v[j].parent].parent;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i].choices.size() == 0)
            continue;
        pair<int, int> minDif = make_pair(-1, INT32_MAX);
        for (int j = 0; j < v[i].choices.size(); j++)
        {
            if (v[i].choices[j].second < minDif.second)
            {
                minDif = v[i].choices[j];
            }
        }
        v[i].val = minDif.second;
        for (int j = 0; j < v[i].choices.size(); j++)
        {
            v[v[i].choices[j].first].val = v[i].choices[j].second - v[i].val;
        }
    }

    unsigned long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += v[i].val;
    }
    cout << ans;
}