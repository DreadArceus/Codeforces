#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long

void solveCase()
{
    int n = 0;
    string s;
    cin >> n >> s;

    set<char> colors;
    colors.insert('R');
    colors.insert('G');
    colors.insert('B');

    int moves = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
            continue;
        set<char>::iterator it = colors.find(s[i]);
        while (*it == s[i] || ((i == n - 1) ? false : *it == s[i + 1]))
        {
            it++;
            if (it == colors.end())
                it = colors.begin();
        }
        s[i] = *it;
        moves++;
    }

    cout << moves << "\n" + s;
}

int32_t main()
{
    solveCase();
}