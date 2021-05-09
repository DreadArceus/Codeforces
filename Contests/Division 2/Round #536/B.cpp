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

int n, m, x, k, l, r;
bool f1, f2, f3;
string s, s1, s2;
vector<int> v, v1, v2;
set<int> se, se1, se2;
map<int, int> mp1, mp2;
void initiateCase()
{
    n = m = x = k = l = r = 0;
    f1 = f2 = f3 = false;
    s = s1 = s2 = string();
    v = v1 = v2 = vector<int>();
    se = se1 = se2 = set<int>();
    mp1 = mp2 = map<int, int>();
}

void solveCase()
{
    initiateCase();
    cin >> n >> m;
    v.resize(n);
    v1.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    set<pii> track;
    for (int i = 0; i < n; i++)
    {
        track.insert(make_pair(v1[i], i));
    }
    while (m--)
    {
        int t = 0, d = 0;
        cin >> t >> d;
        int cost = 0;
        if (v[t - 1] >= d)
        {
            v[t - 1] -= d;
            cost += v1[t - 1] * d;
            d = 0;
        }
        else if (v[t - 1] > 0)
        {
            cost += v[t - 1] * v1[t - 1];
            d -= v[t - 1];
            v[t - 1] = 0;
            track.erase(make_pair(v1[t - 1], t - 1));
        }
        while (d != 0 && !track.empty())
        {
            auto x = track.begin();
            if (v[x->second] >= d)
            {
                v[x->second] -= d;
                cost += x->first * d;
                d = 0;
            }
            else
            {
                cost += v[x->second] * v1[x->second];
                d -= v[x->second];
                v[x->second] = 0;
                track.erase(x);
            }
        }
        if (!f1)
            f1 = track.empty() && d != 0;
        if (f1)
            cout << "0\n";
        else
            cout << cost << "\n";
    }
    cout << "\n";
}

int32_t main()
{
    solveCase();
}