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

int spPow(int x, int y)
{
    int ans = 1;
    while(y--)
    {
        ans *= x;
        ans %= int32_t(1e9 + 7);
    }
    return ans;
}

void solveCase()
{
    int n = 0, k = 0;
    cin >> n >> k;
    int maxVal = (1 << k) - 1;
    int ways = spPow(n, k);
    cout << ways << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}