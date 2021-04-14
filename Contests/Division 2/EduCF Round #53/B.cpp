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
    int n = 0;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        m[x] = i + 1;
    }
    int taken = 0;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        if (taken > m[x])
        {
            cout << 0 << " ";
            continue;
        }
        int cnt = m[x] - taken;
        cout << cnt << " ";
        taken += cnt;
    }
}

int32_t main()
{
    solveCase();
}