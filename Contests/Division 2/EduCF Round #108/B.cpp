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

void solveCase()
{
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    cout << ((m - 1 + (n - 1) * m == k) ? "YES" : "NO") << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}