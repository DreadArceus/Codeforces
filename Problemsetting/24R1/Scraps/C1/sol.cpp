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
    if (a + b == 2)
    {
        cout << "-1\n";
        return;
    }
    if (a == 1)
        cout << a + b - 1 << " " << 1;
    else
        cout << 1 << " " << a + b - 1;
    cout << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}