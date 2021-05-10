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
    int x = 0, y = 0, z = 0;
    cin >> x >> y >> z;
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    a -= x;
    if (a < 0)
        f1 = true;
    if (a >= y)
        a -= y;
    else
    {
        b -= y - a;
        a = 0;
        if (b < 0)
            f1 = true;
    }
    if ((a + b + c) < z)
        f1 = true;
    cout << ((!f1) ? "YES" : "NO") << "\n";
}

int32_t main()
{
    solveCase();
}