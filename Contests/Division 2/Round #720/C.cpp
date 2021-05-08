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
    int t = 2, i = -1, j = 0, x = 1, ans = 0;
    vector<pii> pos;
    int final = -1;
    while (final == -1)
    {
        j += 2 - (i == 1 && n % 2);
        i += 2 - (i == 1 && n % 2);
        if (j > n)
            break;
        cout << "? " << t << " " << i << " " << j << " " << x << endl;
        cin >> ans;
        if (ans == -1)
            exit(0);
        if (ans == 1)
            final = i;
        else if (ans == 2)
            pos.push_back(make_pair(i, j));
    }
    if (final == -1)
    {
        for (auto p : pos)
        {
            cout << "? " << t << " " << p.second << " " << p.first << " " << x << endl;
            cin >> ans;
            if (ans == -1)
                exit(0);
            if (ans == 1)
            {
                final = p.second;
                break;
            }
        }
    }
    t = 1, i = final, j = 1, x = n - 1;
    v.resize(n);
    v[final - 1] = 1;
    if (j == i)
        j++;
    while (j <= n)
    {
        cout << "? " << t << " " << i << " " << j << " " << x << endl;
        cin >> ans;
        if (ans == -1)
            exit(0);
        v[j - 1] = ans;
        j++;
        if (j == i)
            j++;
    }
    cout << "! ";
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}