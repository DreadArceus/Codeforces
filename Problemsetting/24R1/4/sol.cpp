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

void solveCase()
{
    int a = 0, b = 0;
    cin >> a >> b;
    cout << min(min(a, b), (a + b) / 4) << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}