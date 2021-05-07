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
    cin >> n;
    v.resize(n);
    f1 = false;
    int ind = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 1)
        {
            f1 = true;
            ind = i;
        }
    }
    int x = INT32_MAX;
    ind = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < x)
        {
            x = v[i];
            ind = i;
        }
    }
    cout << n - 1 << "\n";
    int r = 1;
    for (int i = ind; i >= 1; i--)
    {
        cout << ind + 1 << " " << i << " "
             << x << " " << x + r << "\n";
        r++;
    }
    r = 1;
    for (int i = ind; i < n - 1; i++)
    {
        cout << ind + 1 << " " << i + 2 << " "
             << x << " " << x + r << "\n";
        r++;
    }
    cout << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}