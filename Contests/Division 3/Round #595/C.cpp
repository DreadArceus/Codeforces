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

vector<int> pow3;
int maxSum = 0;

void solveCase()
{
    int n = 0;
    cin >> n;
    if(n > maxSum)
    {
        cout << pow3[37] * 3 << endl;
        return;
    }
    int sum = maxSum;
    for (int i = 37; i >= 0; i--)
        if (sum - pow3[i] >= n)
            sum -= pow3[i];
    cout << sum << "\n";
}

int32_t main()
{
    pow3.push_back(1);
    maxSum = 1;
    for (int i = 1; i < 38; i++)
    {
        pow3.push_back(pow3[i - 1] * 3);
        maxSum += pow3[i];
    }
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}