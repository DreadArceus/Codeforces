#include <iostream>
#include <iomanip>
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
    cin >> n >> k >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    long double ans = 0;
    if (m >= n)
    {
        v[n - 1] += min(m - n + 1, k);
        ans = v[n - 1];
    }
    else
    {
        int first1 = -1, first2 = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[n - 1] - v[i] > 0)
                break;
            first1 = i;
        }
        for (int i = first1; i >= 0; i--)
        {
            if (v[n - 1] - v[i] > 1)
                break;
            first2 = i;
        }
        int size = n - m;
        if (m > first1)
        {
            v[n - 1] += m - first1;
            size = n - first1;
        }
        else if (m > first2)
        {
            v[n - 1] += m - first2;
            size = n - first2;
        }
        for (int i = n - 1; i >= n - size; i--)
            ans += v[i] / (double)size;
    }
    cout << setprecision(10) << ans;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solveCase();
}