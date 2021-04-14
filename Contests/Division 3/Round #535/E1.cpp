#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<pair<int, int> > segments(m, make_pair(0, 0));
    for (int i = 0; i < m; i++)
        cin >> segments[i].first >> segments[i].second;

    int maxAns = -1 * INT32_MAX;
    vector<int> segUsed;
    for (int x = 0; x < n; x++)
    {
        int maxA = a[x];
        int minA = INT32_MAX;
        vector<int> locSegUsed;
        for (int i = 0; i < n; i++)
        {
            int locA = a[i];
            vector<int> temp;
            for (int j = 0; j < m; j++)
            {
                pair<int, int> seg = segments[j];
                if (seg.first - 1 <= i && seg.second - 1 >= i)
                {
                    if (seg.first - 1 > x || seg.second - 1 < x)
                    {
                        temp.push_back(j + 1);
                    }
                }
            }
            locA -= temp.size();
            if (locA < minA)
            {
                minA = locA;
                locSegUsed = temp;
            }
        }
        int locAns = maxA - minA;
        if(locAns > maxAns)
        {
            maxAns = locAns;
            segUsed = locSegUsed;
        }
    }

    cout << maxAns << "\n";
    cout << segUsed.size() << "\n";
    for (int i = 0; i < segUsed.size(); i++)
    {
        cout << segUsed[i] << " ";
    }
}

int32_t main()
{
    solveCase();
}