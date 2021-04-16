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
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> v(n);
    int maxDif = INT32_MIN;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 1)
            cnt1++;
        else
            cnt2++;
    }
    for (int i = 0; i < k; i++)
    {
        int loc1 = cnt1, loc2 = cnt2;
        for (int j = i; j < n; j += k)
        {
            if (v[j] == 1)
                loc1--;
            else
                loc2--;
        }
        if (abs(loc1 - loc2) > maxDif)
        {
            maxDif = abs(loc1 - loc2);
        }
    }
    cout << maxDif;
}

int32_t main()
{
    solveCase();
}