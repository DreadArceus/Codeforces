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
    cin >> n;
    vector<int> even;
    vector<int> odd;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        if (x % 2)
            odd.push_back(x);
        else
            even.push_back(x);
    }
    for(auto i : even)
    {
        cout << i << " ";
    }
    for(auto i : odd)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}