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
    int n = 0;
    cin >> n;
    if (n % 2)
    {
        cout << "NO\n";
        return;
    }
    while (n % 2 == 0)
        n /= 2;
    cout << ((sqrt(n) == int32_t(sqrt(n))) ? "YES" : "NO") << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}