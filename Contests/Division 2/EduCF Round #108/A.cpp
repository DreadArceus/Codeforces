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
    int r = 0, b = 0, d = 0;
    cin >> r >> b >> d;
    if (r > b)
        swap(r, b);
    cout << ((r * (d + 1) >= b) ? "YES" : "NO") << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}