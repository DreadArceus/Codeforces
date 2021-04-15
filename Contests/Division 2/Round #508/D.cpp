#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
#define pii pair<int, int>

void solveCase()
{
    int n = 0;
    cin >> n;
    vector<int> a(n);
    int minSlime = INT32_MAX, negMaxSlime = INT32_MIN, negSum = 0, posSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
            negSum += a[i];
        if (a[i] > 0)
            posSum += a[i];
        if (a[i] >= 0 && minSlime > a[i])
            minSlime = a[i];
        if (a[i] < 0 && negMaxSlime < a[i])
            negMaxSlime = a[i];
    }
    if (minSlime == INT32_MAX)
    {
        cout << ((negSum == negMaxSlime) ? negSum : negMaxSlime * 2 - negSum);
        return;
    }
    cout << ((posSum == minSlime) ? posSum : posSum - minSlime * 2) - negSum;
}

int32_t main()
{
    solveCase();
}