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
    int n = 0, T = 0;
    cin >> n >> T;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int down = 0, candyCnt = 0;
    while (down != n)
    {
        candyCnt += (T / sum) * (n - down);
        T -= sum * (T / sum);
        for (int i = 0; i < n; i++)
        {
            if(a[i] == -1) continue;
            if (a[i] <= T)
            {
                candyCnt++;
                T -= a[i];
            }
            else
            {
                sum -= a[i];
                a[i] = -1;
                down++;
            }
        }
    }
    cout << candyCnt;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solveCase();
}