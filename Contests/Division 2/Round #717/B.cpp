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
    vector<int> v(n);
    int totalXor = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i == 0)
            totalXor = v[i];
        else
            totalXor ^= v[i];
    }
    if (totalXor == 0)
    {
        cout << "YES\n";
        return;
    }
    int runningXor = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        runningXor ^= v[i];
        if (runningXor == totalXor)
        {
            if (cnt++ == 1)
            {
                cout << "YES\n";
                return;
            }
            runningXor = 0;
        }
    }
    cout << "NO\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}