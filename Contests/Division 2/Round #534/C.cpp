#include <iostream>
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

int n, m, x, k, l, r;
bool f1, f2, f3;
string s, s1, s2;
vector<int> v, v1, v2;
set<int> se, se1, se2;
map<int, int> mp1, mp2;
void initiateCase()
{
    n = m = x = k = l = r = 0;
    f1 = f2 = f3 = false;
    s = s1 = s2 = string();
    v = v1 = v2 = vector<int>();
    se = se1 = se2 = set<int>();
    mp1 = mp2 = map<int, int>();
}

void solveCase()
{
    initiateCase();
    cin >> s;
    int grid[4][4];
    memset(grid, 0, sizeof(grid));
    for (int i = 0; i < s.length(); i++)
    {
        int r = 0, c = 0;
        if (s[i] == '0')
        {
            for (int x = 0; x < 4; x++)
            {
                int sum = 0;
                for (int y = 0; y < 4; y++)
                    sum += grid[y][x];
                if (sum == 2)
                {
                    for (int y = 0; y < 3; y++)
                    {
                        if (grid[y][x] == 0 && grid[y + 1][x] == 0)
                        {
                            grid[y][x] = grid[y + 1][x] = 1;
                            r = y + 1;
                            c = x + 1;
                            break;
                        }
                    }
                    if (r + c)
                        break;
                }
            }
            if (r + c == 0)
            {
                for (int x = 0; x < 4; x++)
                {
                    int sum = 0;
                    for (int y = 0; y < 4; y++)
                        sum += grid[x][y];
                    if (sum == 3)
                    {
                        for (int y = 0; y < 4; y++)
                        {
                            if (grid[x][y] == 0)
                            {
                                if (x != 3 && grid[x + 1][y] == 0)
                                {
                                    r = x + 1;
                                    grid[x + 1][y] = 1;
                                }
                                else if (x != 0 && grid[x - 1][y] == 0)
                                {
                                    r = x;
                                    grid[x - 1][y] = 1;
                                }
                                else
                                    continue;
                                c = y + 1;
                                grid[x][y] = 1;
                            }
                        }
                        if (r + c)
                            break;
                    }
                }
            }
            if (r + c == 0)
            {
                for (int x = 0; x < 3; x++)
                {
                    for (int y = 0; y < 4; y++)
                    {
                        if (grid[x][y] + grid[x + 1][y] == 0)
                        {
                            grid[x][y] = grid[x + 1][y] = 1;
                            r = x + 1;
                            c = y + 1;
                            break;
                        }
                    }
                    if (r + c)
                        break;
                }
            }
        }
        else
        {
            for (int x = 0; x < 4; x++)
            {
                int sum = 0;
                for (int y = 0; y < 4; y++)
                    sum += grid[x][y];
                if (sum == 2)
                {
                    for (int y = 0; y < 3; y++)
                    {
                        if (grid[x][y] == 0 && grid[x][y + 1] == 0)
                        {
                            grid[x][y] = grid[x][y + 1] = 1;
                            r = x + 1;
                            c = y + 1;
                            break;
                        }
                    }
                    if (r + c)
                        break;
                }
            }
            if (r + c == 0)
            {
                for (int x = 0; x < 4; x++)
                {
                    int sum = 0;
                    for (int y = 0; y < 4; y++)
                        sum += grid[y][x];
                    if (sum == 3)
                    {
                        for (int y = 0; y < 4; y++)
                        {
                            if (grid[y][x] == 0)
                            {
                                if (x != 3 && grid[y][x + 1] == 0)
                                {
                                    c = x + 1;
                                    grid[y][x + 1] = 1;
                                }
                                else if (x != 0 && grid[y][x - 1] == 0)
                                {
                                    c = x;
                                    grid[y][x - 1] = 1;
                                }
                                else
                                    continue;
                                grid[y][x] = 1;
                                r = y + 1;
                            }
                        }
                        if (r + c)
                            break;
                    }
                }
            }
            if (r + c == 0)
            {
                for (int x = 0; x < 4; x++)
                {
                    for (int y = 0; y < 3; y++)
                    {
                        if (grid[x][y] + grid[x][y + 1] == 0)
                        {
                            grid[x][y] = grid[x][y + 1] = 1;
                            r = x + 1;
                            c = y + 1;
                            break;
                        }
                    }
                    if (r + c)
                        break;
                }
            }
        }
        cout << r << " " << c << "\n";
        bool r1 = false, r2 = false;
        int sum = 0;
        for (int y = 0; y < 4; y++)
            sum += grid[r - 1][y];
        r1 = sum == 4;
        sum = 0;
        for (int y = 0; y < 4; y++)
            sum += grid[y][c - 1];
        r2 = sum == 4;
        sum = 0;
        if (s[i] == '0')
        {
            for (int y = 0; y < 4; y++)
                sum += grid[r][y];
            if (sum == 4)
                for (int y = 0; y < 4; y++)
                    grid[r][y] = 0;
        }
        else
        {
            for (int y = 0; y < 4; y++)
                sum += grid[y][c];
            if (sum == 4)
                for (int y = 0; y < 4; y++)
                    grid[y][c] = 0;
        }
        if (r1)
            for (int y = 0; y < 4; y++)
                grid[r - 1][y] = 0;
        if (r2)
            for (int y = 0; y < 4; y++)
                grid[y][c - 1] = 0;
    }
    cout << "\n";
}

int32_t main()
{
    solveCase();
}