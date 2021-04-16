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
    string s;
    cin >> n >> s;
    vector<int> v(2, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'T')
            v[0]++;
        else
            v[1]++;
        if (v[1] > v[0])
        {
            cout << "NO\n";
            return;
        }
    }
    v[0] = 0;
    v[1] = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if (s[i] == 'T')
            v[0]++;
        else
            v[1]++;
        if (v[1] > v[0])
        {
            cout << "NO\n";
            return;
        }
    }
    if (v[0] / 2 == v[1])
        cout << "YES";
    else
        cout << "NO";
    cout << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}