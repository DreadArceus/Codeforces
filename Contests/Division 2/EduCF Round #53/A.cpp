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
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            cout << "YES\n";
            cout << s[i] << s[i + 1];
            return;
        }
    }
    cout << "NO";
}

int32_t main()
{
    solveCase();
}