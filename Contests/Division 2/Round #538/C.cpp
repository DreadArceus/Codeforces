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
    int nq = 0, b = 0;
    cin >> nq >> b;
    int largestPrime = b, freq = 1;
    int ans = 0;
    for (int i = 2 * sqrt(b); i >= 2; i--)
    {
        if (b % i == 0)
        {
            largestPrime = i;
            break;
        }
    }
    while (nq >= largestPrime)
    {
        ans += nq / largestPrime;
        largestPrime *= largestPrime;
    }
    cout << ans;
}

int32_t main()
{
    solveCase();
}