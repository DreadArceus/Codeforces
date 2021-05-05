#include <iostream>
#include <stack>
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
    stack<char> sk;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (sk.empty() || s[i] != sk.top())
            sk.push(s[i]);
        else
        {
            sk.pop();
            cnt++;
        }
    }
    cout << (cnt % 2 ? "Yes" : "No") << "\n";
}

int32_t main()
{
    solveCase();
}