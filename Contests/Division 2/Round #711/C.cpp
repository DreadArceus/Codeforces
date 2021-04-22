#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define int long long
#define pii pair<int, int>
#define MAX_N 1010
int32_t m = 1e9 + 7;

int n = 0, k = 0;
int cache[MAX_N][MAX_N];
int dp(int planeCnt, int decay)
{
    if (decay == 1)
        return 0;
    if (planeCnt == 1)
        return 1;
    int res1 = cache[planeCnt - 1][decay];
    if (res1 == -1)
        res1 = cache[planeCnt - 1][decay] = dp(planeCnt - 1, decay);
    int res2 = cache[n - planeCnt][decay - 1];
    if (res2 == -1)
        res2 = cache[n - planeCnt][decay - 1] = dp(n - planeCnt, decay - 1);
    return (1 + res1 + res2) % m;
}

void solveCase()
{
    cin >> n >> k;
    memset(cache, -1, sizeof(cache));
    cout << dp(n, k) + 1 << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}