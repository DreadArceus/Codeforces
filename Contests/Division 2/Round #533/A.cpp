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

int n, m, x, l, r;
bool f1, f2, f3;
string s, s1, s2;
vector<int> v, v1, v2;
set<int> se, se1, se2;
map<int, int> mp1, mp2;
void initiateCase()
{
    n = m = x = l = r = 0;
    f1 = f2 = f3 = false;
    s = s1 = s2 = string();
    v = v1 = v2 = vector<int>();
    se = se1 = se2 = set<int>();
    mp1 = mp2 = map<int, int>();
}

void solveCase()
{
    initiateCase();
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int t = -1, minCost = INT32_MAX;
    for (int x = 1; x <= 100; x++)
    {
        int cost = 0;
        for (int i = 0; i < n; i++)
            cost += max(abs(v[i] - x) - 1, (int)0);
        if (cost < minCost)
        {
            minCost = cost;
            t = x;
        }
    }
    cout << t << " " << minCost << "\n";
}

int32_t main()
{
    solveCase();
}