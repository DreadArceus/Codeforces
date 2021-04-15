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
#define pvii pair<vector<int>, int>
#define psii pair<set<int>, int>

vector<int> a;
bool heatSort(psii _a, psii _b)
{
    return _a.first.size() > _b.first.size();
}

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<psii> heatMap(n, make_pair(set<int>(), 0));
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        a.push_back(x);
        heatMap[i].second = i;
    }
    vector<pii> segments(m, make_pair(0, 0));
    for (int i = 0; i < m; i++)
    {
        cin >> segments[i].first >> segments[i].second;
        for (int j = segments[i].first - 1; j < segments[i].second; j++)
            heatMap[j].first.insert(i + 1);
    }
    sort(heatMap.begin(), heatMap.end(), heatSort);

    int maxAns = INT32_MIN;
    set<int> segAvail;
    for (int i = 0; i < n; i++)
    {
        set<int> allSeg = heatMap[i].first;
        int minA = a[heatMap[i].second];
        int maxA = INT32_MIN;
        set<int> segUsed;
        for (int j = n - 1; j >= 0; j--)
        {
            set<int> badSeg = heatMap[j].first;
            set<int> finalSeg;
            set<int>::iterator it = allSeg.begin();
            for (; it != allSeg.end(); it++)
            {
                if (badSeg.find(*it) == badSeg.end())
                    finalSeg.insert(*it);
            }
            int locA = a[heatMap[j].second] + finalSeg.size();
            if (locA > maxA)
            {
                maxA = locA;
                segUsed = finalSeg;
            }
        }
        if (maxA - minA > maxAns)
        {
            maxAns = maxA - minA;
            segAvail = segUsed;
        }
        else
            break;
    }

    cout << maxAns << "\n";
    cout << segAvail.size() << "\n";
    set<int>::iterator it = segAvail.begin();
    for (; it != segAvail.end(); it++)
    {
        cout << *it << " ";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solveCase();
}