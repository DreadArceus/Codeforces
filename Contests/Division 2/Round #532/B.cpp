#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
#define pii pair<int, int>

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> mp(n + 1);
    map<int, int> cnt;
    for (int i = 0; i < m; i++)
    {
        int x = 0;
        cin >> x;
        if (++cnt[++mp[x]] == n)
            cout << 1;
        else
            cout << 0;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solveCase();
}