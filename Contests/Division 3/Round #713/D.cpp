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
    int sum = 0;
    for (int i = 0; i < n + 2; i++)
    {
        cin >> k;
        sum += k;
        se.insert(k);
        mp1[k]++;
    }
    for (auto it : se)
    {
        x = it;
        if ((sum - x) & 1)
            continue;
        m = (sum - x) / 2;
        if (mp1[m] > (x == m))
        {
            f1 = true;
            mp1[m]--;
            mp1[x]--;
            break;
        }
    }
    if (!f1)
    {
        cout << "-1\n";
        return;
    }
    for (auto it : mp1)
        while (it.second--)
            cout << it.first << " ";
    cout << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}