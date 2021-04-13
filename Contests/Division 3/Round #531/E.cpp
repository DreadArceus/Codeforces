#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
#define pii pair<int, int>

long long modPow(int x, int y)
{
    long long ans = 1;
    while (y--)
    {
        ans *= x;
        ans %= 998244353;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0;
    cin >> n;
    vector<int> v(n);
    map<int, pii> rangeMap;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        rangeMap[v[i]] = make_pair(i, i);
    }

    for (int i = 0; i < n; i++)
    {
        pii current = rangeMap[v[i]];
        if (current.first > i)
            rangeMap[v[i]].first = i;
        if (current.second < i)
            rangeMap[v[i]].second = i;
    }

    int cnt = -1, rightReach = -1;
    queue<int> tracker;
    for (int i = 0; i < n; i++)
    {
        if (tracker.size() == 0)
            cnt++;
        else if (tracker.front() == v[i] && i == rangeMap[v[i]].second)
            tracker.pop();

        if (i == rangeMap[v[i]].first && rangeMap[v[i]].first != rangeMap[v[i]].second)
        {
            if (tracker.size() != 0)
            {
                pii newRange = rangeMap[v[i]];
                if (rightReach >= newRange.second)
                    continue;
            }
            tracker.push(v[i]);
            rightReach = rangeMap[v[i]].second;
        }
    }

    cout << modPow(2, cnt);
}