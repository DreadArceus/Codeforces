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
    if (n < 3)
    {
        cout << "No";
        return;
    }
    cout << "Yes\n";
    cout << n / 2 << " ";
    for (int i = 1; i < n; i += 2)
    {
        cout << i + 1 << " ";
    }
    cout << "\n";
    cout << n / 2 + n % 2 << " ";
    for (int i = 0; i < n; i+=2)
    {
        cout << i + 1 << " ";
    }
}

int32_t main()
{
    solveCase();
}