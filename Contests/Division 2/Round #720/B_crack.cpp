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
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    int x = INT32_MAX, ind = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < x)
        {
            x = v[i];
            ind = i;
        }
    }
    if(n == 2)
    {
        cout << "1\n";
        cout << 1 << " " << 2 << " "
             << x << " " << x + 1 << "\n";
        return;
    }
    int r = 0;
    if (ind != 0 && ind != n - 1)
    {
        cout << n - 1 << "\n";
        cout << ind + 1 << " " << ind + 2 << " " << x << " " << x << "\n";
        v[ind + 1] = x;
    }
    else
        cout << n - 2 << "\n";
    for (int i = ind; i >= 1; i--)
    {
        if (i == 1)
        {
            cout << "1 2 " << x << " " << x * v[2] + 1 << "\n";
            v[0] = x;
            v[1] = x * v[2] + 1;
            break;
        }
        cout << i << " " << i + 1 << " "
             << x << " " << x + r + 1 << "\n";
        v[i - 1] = x;
        v[i] = x + r + 1;
        r++;
    }
    r = 0;
    for (int i = ind + 2; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << i << " " << i + 1 << " "
                 << x * v[n - 3] + 1 << " " << x << "\n";
            break;
        }
        cout << i << " " << i + 1 << " "
             << x + r + 2 << " " << x << "\n";
        v[i - 1] = x + r + 2;
        v[i] = x;
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