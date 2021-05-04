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
    int n = 0, x = 0;
    vector<int> mp(101, 0);
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        mp[w[i]]++;
    }
    int sum = 0;
    for (int i = 1; i < 101; i++)
    {
        if (mp[i])
            sum += i;
    }
    if (sum == x)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    sum = 0;
    int delayer = -1;
    for (int i = 1; i < 101; i++)
    {
        if (!mp[i])
            continue;
        int j;
        bool delay = false;
        for (j = 0; j < mp[i]; j++)
        {
            if (sum + i == x)
            {
                delay = true;
                break;
            }
            cout << i << " ";
            sum += i;
        }
        if (delay)
        {
            mp[i] -= j;
            delayer = i;
        }
    }
    if (delayer != -1)
        for (int j = 0; j < mp[delayer]; j++)
            cout << delayer << " ";
    cout << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}