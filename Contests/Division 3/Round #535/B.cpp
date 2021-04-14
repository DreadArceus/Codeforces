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
    cin >> n;
    vector<int> v(n);
    map<int, int> divisorMap;
    int x = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(x < v[i])
            x = v[i];
        divisorMap[v[i]]++;
    }
    vector<int> yDivs;
    for(int i = 0; i < n; i++)
    {
        if(x % v[i] != 0 || divisorMap[v[i]] == 2)
        {
            yDivs.push_back(v[i]);
            divisorMap[v[i]]--;
        }
    }
    int y = *max_element(yDivs.begin(), yDivs.end());
    cout << x << " " << y;
}

int32_t main()
{
    solveCase();
}