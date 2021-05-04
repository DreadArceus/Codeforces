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
    cout << "2\n";
    int cur = n;
    for (int i = n - 1; i > 0; i--)
    {
        cout << i << " " << cur << "\n";
        cur = (cur + i + 1) / 2;
    }
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}