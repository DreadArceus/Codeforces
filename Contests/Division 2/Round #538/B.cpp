#include <iostream>
#include <queue>
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
    cin >> n >> m >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    set<pii> tr;
    for (int i = 0; i < n; i++)
        tr.insert(make_pair(v[i], i));

    int shadowCnt = n - m * k;
    priority_queue<int, vector<int>, greater<int>> shadows;
    for (auto x : tr)
    {
        if (shadows.size() == shadowCnt)
            break;
        shadows.push(x.second);
    }

    int beauty = 0, rc = 0;
    vector<int> segments;
    for (int i = 0; i < n; i++)
    {
        if (!shadows.empty() && shadows.top() == i)
        {
            shadows.pop();
            continue;
        }
        beauty += v[i];
        rc++;
        if (rc == m)
        {
            segments.push_back(i);
            rc = 0;
            continue;
        }
    }
    segments.pop_back();
    cout << beauty << "\n";
    for (auto x : segments)
        cout << x + 1 << " ";
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solveCase();
}