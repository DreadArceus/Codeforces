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
    cin >> n >> k >> s;
    vector<int> starPos;
    for (int i = 0; i < n; i++)
        if (s[i] == '*')
            starPos.push_back(i);
    int last = starPos[0], ans = 1;
    for (int i = 1; i < starPos.size() - 1; i++)
    {
        if (starPos[i + 1] - last > k)
        {
            ans++;
            last = starPos[i];
        }
    }
    cout << ans + (starPos.size() > 1) << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}