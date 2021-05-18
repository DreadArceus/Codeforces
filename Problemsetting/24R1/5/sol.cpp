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
    vector<int> v(n), ans(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    stack<pii> sk;
    for (int i = 0; i < n; i++)
    {
        while (!sk.empty() && sk.top().first <= v[i])
            sk.pop();
        if (sk.empty())
            ans[i] = -1;
        else
            ans[i] = sk.top().second;
        sk.push(make_pair(v[i], i));
    }
    sk = stack<pii>();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!sk.empty() && sk.top().first <= v[i])
            sk.pop();
        if (!sk.empty())
            if (ans[i] == -1 || abs(ans[i] - i) > abs(sk.top().second - i))
                ans[i] = sk.top().second;
        sk.push(make_pair(v[i], i));
    }
    for (auto x : ans)
        cout << x << " ";
}

int32_t main()
{
    solveCase();
}