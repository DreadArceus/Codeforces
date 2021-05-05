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
    v.resize(2);
    cin >> v[0] >> v[1] >> s;
    for (int i = 0; i < s.length() / 2; i++)
    {
        int palI = s.length() - 1 - i;
        if (s[i] != '?' && s[palI] == '?')
        {
            s[palI] = s[i];
            v[s[i] - '0'] -= 2;
        }
        else if (s[i] == '?' && s[palI] != '?')
        {
            s[i] = s[palI];
            v[s[palI] - '0'] -= 2;
        }
        else if (s[i] != '?' && s[palI] != '?')
        {
            v[s[i] - '0'] -= 2;
            if (s[i] != s[palI])
                v[0] = v[1] = -1;
        }
    }
    for (int i = 0; i < s.length() / 2; i++)
    {
        int palI = s.length() - 1 - i;
        if (s[i] == '?' && s[palI] == '?')
        {
            if (v[0] > v[1])
            {
                v[0] -= 2;
                s[i] = s[palI] = '0';
            }
            else
            {
                v[1] -= 2;
                s[i] = s[palI] = '1';
            }
        }
    }
    if (s.length() % 2)
    {
        int i = s.length() / 2;
        if (s[i] != '?')
        {
            v[s[i] - '0']--;
        }
        else
        {
            if (v[0] > v[1])
            {
                v[0]--;
                s[i] = '0';
            }
            else
            {
                v[1]--;
                s[i] = '1';
            }
        }
    }
    if (v[0] != 0 || v[1] != 0)
    {
        cout << "-1\n";
        return;
    }
    cout << s << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}