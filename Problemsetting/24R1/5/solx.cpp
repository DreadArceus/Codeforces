#include <iostream>
#include <stack>
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
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
    {
        int ans = -1;
        for (int j = i; j >= 0; j--)
        {
            if (v[j] > v[i])
            {
                ans = j;
                break;
            }
        }
        for (int j = i; j < min((ans != -1 ? i + abs(ans - i) : n), n); j++)
        {
            if (v[j] > v[i])
            {
                if (ans == -1 || abs(j - i) < abs(ans - i))
                    ans = j;
                break;
            }
        }
        cout << ans << " ";
    }
}

int32_t main()
{
    solveCase();
}