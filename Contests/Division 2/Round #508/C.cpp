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

bool rev(int a, int b)
{
    return a > b;
}

void solveCase()
{
    int n = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int scoreA = 0, scoreB = 0;
    while(a.size() || b.size())
    {
        if(b.size() == 0 || (a.size() && a[a.size() - 1] > b[b.size() - 1]))
        {
            scoreA += a[a.size() - 1];
            a.pop_back();
        }
        else
        {
            b.pop_back();
        }
        if(a.size() == 0 && b.size() == 0) break;
        if(b.size() == 0 || (a.size() && a[a.size() - 1] > b[b.size() - 1]))
        {
            a.pop_back();
        }
        else
        {
            scoreB += b[b.size() - 1];
            b.pop_back();
        }
    }
    cout << scoreA - scoreB;
}

int32_t main()
{
    solveCase();
}