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
    vector<string> s(3);
    cin >> n >> s[0] >> s[1] >> s[2];
    vector<vector<int>> counts(3, vector<int>(2, 0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if (s[i][j] == '0')
                counts[i][0]++;
            if (s[i][j] == '1')
                counts[i][1]++;
        }
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                continue;
            for (char c = '0'; c <= '1'; c++)
            {
                if (min(counts[i][c - '0'], counts[j][c - '0']) < n)
                    continue;
                string ans;
                int x = 0, y = 0;
                while (x < 2 * n && y < 2 * n)
                {
                    if (s[i][x] == c && s[j][y] == c)
                    {
                        ans += c;
                        x++;
                        y++;
                    }
                    else
                    {
                        if(s[i][x] == s[j][y])
                        {
                            ans += s[i][x];
                            x++;
                            y++;
                            continue;
                        }
                        if (s[i][x] != c)
                        {
                            ans += s[i][x++];
                        }
                        if (s[j][y] != c)
                        {
                            ans += s[j][y++];
                        }
                    }
                }
                while (x < 2 * n)
                    ans += s[i][x++];
                while (y < 2 * n)
                    ans += s[j][y++];
                cout << ans << "\n";
                return;
            }
        }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}