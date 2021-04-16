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
    string s1, s2, s3;
    cin >> n >> s1 >> s2 >> s3;
    vector<char> ans;
    for (int i = 0; i < 2 * n; i++)
    {
        if (s1[i] == s2[i])
        {
            ans.push_back(s1[i]);
        }
        else
        {
            ans.push_back(s1[i]);
            ans.push_back(s2[i]);
        }
    }
    if (ans.size() > 3 * n)
    {
        ans = vector<char>();
        for (int i = 0; i < 2 * n; i++)
        {
            if (s1[i] == s3[i])
            {
                ans.push_back(s1[i]);
            }
            else
            {
                ans.push_back(s1[i]);
                ans.push_back(s3[i]);
            }
        }
    }
    if (ans.size() > 3 * n)
    {
        ans = vector<char>();
        for (int i = 0; i < 2 * n; i++)
        {
            if (s2[i] == s3[i])
            {
                ans.push_back(s2[i]);
            }
            else
            {
                ans.push_back(s2[i]);
                ans.push_back(s3[i]);
            }
        }
    }
    for (char bit : ans)
    {
        cout << bit - '0';
    }
    int remaining = 3 * n - ans.size();
    while (remaining--)
    {
        cout << 0;
    }
    cout << "\n";
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