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
    int n = 0, k = 0;
    string s;
    cin >> n >> k >> s;
    map<char, int> m;
    for(int i = 0; i < k; i++)
    {
        m[i + 'A'] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        m[s[i]]++;
    }
    int minOcc = INT32_MAX;
    for (int i = 0; i < k; i++)
    {
        if(minOcc > m[i +'A'])
            minOcc = m[i + 'A'];
    }
    cout << minOcc * k << endl;
}

int32_t main()
{
    solveCase();
}