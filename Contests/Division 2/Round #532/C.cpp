// MATH
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
#define pii pair<int, int>
#define PI 3.141592653589793

void solveCase()
{
    int n = 0, r = 0;
    cin >> n >> r;
    long double ans = (r * sin(PI / n)) / (1 - sin(PI / n));
    cout << fixed << setprecision(7) << ans;
}

int32_t main()
{
    solveCase();
}