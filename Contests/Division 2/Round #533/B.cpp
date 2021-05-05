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
    int ans = 0;
    for (int j = 0; j < 26; j++)
    {
        vector<string> vs;
        string cur;
        for (int i = 0; i < n; i++)
        {
            if (s[i] - 'a' != j && cur.size())
            {
                if (cur.size() == k)
                    vs.push_back(cur);
                cur.clear();
            }
            if (s[i] - 'a' == j)
            {
                cur.push_back(s[i]);
                if (cur.size() == k)
                {
                    vs.push_back(cur);
                    cur.clear();
                }
            }
        }
        ans = max(ans, (int)vs.size());
    }
    cout << ans << "\n";
}

int32_t main()
{
    solveCase();
}