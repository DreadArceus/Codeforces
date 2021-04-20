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
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        if (sqrt(x) > int32_t(sqrt(x)))
        {
            found = true;
        }
    }
    if (found)
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