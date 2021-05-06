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
    if (n == 2)
    {
        cout << "-1\n";
        return;
    }
    int grid[n][n];
    memset(grid, 0, sizeof(grid));
    int cur = 1;
    for (int x = 0; x < n; x++)
    {
        for (int i = 0; i + x < n; i++)
        {
            grid[i][i + x] = cur++;
        }
        if (x == 0)
            continue;
        for (int i = 0; i + x < n; i++)
        {
            grid[i + x][i] = cur++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}