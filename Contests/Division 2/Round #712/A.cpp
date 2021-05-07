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
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        mp1[s[i]]++;
    }
    if (mp1['a'] == s.length())
        cout << "NO";
    else
    {
        cout << "YES\n";
        int ans = s.length() - 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[s.length() - 1 - i] != 'a')
            {
                ans = i;
                break;
            }
        }
        for (int i = 0; i < s.length(); i++)
        {
            if(i == ans) cout << 'a';
            cout << s[i];
        }
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