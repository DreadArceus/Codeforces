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
    int ans = 0;
    m = 9;
    int cnt = 0;
    while (n > m)
    {
        ans += 9;
        cnt++;
        m += 9 * pow(10, cnt);
    }
    int base = 0;
    while (cnt >= 0)
    {
        base += pow(10, cnt--);
    }
    int cur = 1;
    while(base <= n)
    {
        ans++;
        base /= cur;
        cur++;
        base *= cur;
    }
    cout << ans << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}