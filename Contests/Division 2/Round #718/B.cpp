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
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> paths(n + 1, vector<int>(m + 1, 0));
    set<pair<int, pii>> sorter;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> paths[i][j];
            sorter.insert(make_pair(paths[i][j], make_pair(i, j)));
        }
    }
    map<int, pair<int, pii>> mp;
    int cnt = 1;
    for (auto st : sorter)
    {
        mp[cnt] = st;
        paths[st.second.first][st.second.second] = -1;
        cnt++;
        if (cnt == m + 1)
            break;
    }
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        for (int x = 1; x <= m; x++)
        {
            if (mp[x].second.first == i)
            {
                cout << mp[x].first << " ";
                continue;
            }
            while (paths[i][j] == -1)
                j++;
            cout << paths[i][j] << " ";
            paths[i][j] = -1;
        }
        cout << "\n";
    }
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}