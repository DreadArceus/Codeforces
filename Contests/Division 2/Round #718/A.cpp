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
    if (n < 2050 || n % 2050)
    {
        cout << "-1\n";
        return;
    }
    n /= 2050;
    string s = to_string(n);
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        cnt += s[i] - '0';
    }
    cout << cnt;
    cout << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}