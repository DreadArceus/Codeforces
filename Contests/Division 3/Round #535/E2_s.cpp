#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define pii pair<int, int>

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<pii> segments(m);
    map<int, vector<int>> leftSide, rightSide;
    for (int i = 0; i < m; i++)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        segments[i] = make_pair(x, y);
        leftSide[y - 1].push_back(x - 1);
        rightSide[x - 1].push_back(y - 1);
    }

    vector<int> ans(n, INT32_MIN);
    vector<int> subTracker(n, 0);
    int minA = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        if (minA > a[i] + subTracker[i])
            minA = a[i] + subTracker[i];
        if (ans[i] < a[i] - minA)
            ans[i] = a[i] - minA;
        for (auto leftEnd : leftSide[i])
        {
            for (int j = leftEnd; j <= i; j++)
            {
                subTracker[j]--;
                if (minA > a[j] + subTracker[j])
                    minA = a[j] + subTracker[j];
            }
        }
    }

    subTracker = vector<int>(n, 0);
    minA = INT32_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (minA > a[i] + subTracker[i])
            minA = a[i] + subTracker[i];
        if (ans[i] < a[i] - minA)
            ans[i] = a[i] - minA;
        for (auto rightEnd : rightSide[i])
        {
            for (int j = i; j <= rightEnd; j++)
            {
                subTracker[j]--;
                if (minA > a[j] + subTracker[j])
                    minA = a[j] + subTracker[j];
            }
        }
    }

    int finalAns = INT32_MIN, ansIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] > finalAns)
        {
            finalAns = ans[i];
            ansIndex = i;
        }
    }
    vector<int> ansSegs;
    for (int i = 0; i < m; i++)
    {
        if (segments[i].first - 1 > ansIndex || segments[i].second - 1 < ansIndex)
            ansSegs.push_back(i + 1);
    }

    cout << finalAns << "\n";
    cout << ansSegs.size() << "\n";
    for (auto i : ansSegs)
        cout << i << " ";
}

int32_t main()
{
    fastIO
    solveCase();
}