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
    int firstNonZero = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] > 0 && firstNonZero == -1)
            firstNonZero = i;
    }
    if (firstNonZero != -1)
    {
        while (k-- && firstNonZero < n - 1)
        {
            v[firstNonZero]--;
            v[n - 1]++;
            while (firstNonZero != n && v[firstNonZero] == 0)
                firstNonZero++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}