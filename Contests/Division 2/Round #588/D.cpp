#include <iostream>
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
    int n = 0;
    cin >> n;
    vector<pii> v(n, make_pair(0, 0));
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        cin >> a;
        v[i].first = a;
        mp[a]++;
    }
    for (int i = 0; i < n; i++)
    {
        int b = 0;
        cin >> b;
        v[i].second = b;
    }
    auto it = mp.begin();
    set<int> ideal;
    while (it != mp.end())
    {
        if (it->second == 1)
        {
            it++;
            continue;
        }
        ideal.insert(it->first);
        it++;
    }
    if (ideal.size() == 0)
    {
        cout << 0;
        return;
    }
    map<int, pii> subAns;
    for (int i = 0; i < n; i++)
    {
        subAns[v[i].first].first += v[i].second;
        subAns[v[i].first].second = min(v[i].second, subAns[v[i].first].second);
    }
    int ans = 0;
    map<int, bool> done;
    for (int i = 0; i < n; i++)
    {
        if (done[v[i].first])
            continue;
        if (ideal.find(v[i].first) != ideal.end())
        {
            ans += subAns[v[i].first].first;
            bool in = false;
            for (auto j : ideal)
            {
                in |= (v[i].first | j) == j;
            }
            if (!in)
                ans -= subAns[v[i].first].second;
            done[v[i].first] = true;
            continue;
        }
        bool in = false;
        for (auto j : ideal)
        {
            in |= (v[i].first | j) == j;
        }
        if (!in)
            continue;
        ans += v[i].second;
    }
    cout << ans;
}

int32_t main()
{
    solveCase();
}