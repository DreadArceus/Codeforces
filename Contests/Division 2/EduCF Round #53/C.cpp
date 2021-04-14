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
    int n = 0, x = 0, y = 0;
    string s;
    cin >> n >> s >> x >> y;
    if (x + y > n)
    {
        cout << -1;
        return;
    }
    int u = 0, d = 0, l = 0, r = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'U')
            u++;
        if (s[i] == 'D')
            d++;
        if (s[i] == 'L')
            l++;
        if (s[i] == 'R')
            r++;
    }
    int xDif = x - (r - l), yDif = y - (u - d);
    int rlShift = xDif / 2, udShift = yDif / 2;
    int xyShift = xDif - 2 * rlShift, yxShift = yDif - 2 * udShift;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'R' && xDif > 0)
        {
            rlShift--;
        }
        else if(s[i] == 'L' && xDif < 0)
        {
            rlShift++;
        }
    }
}

int32_t main()
{
    solveCase();
}