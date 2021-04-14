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
    int l1 = 0, r1 = 0, l2 = 0, r2 = 0;
    cin >> l1 >> r1 >> l2 >> r2;
    if(l1 == l2) l1 = r1;
    cout << l1 << " " << l2 << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        solveCase();
    }
}