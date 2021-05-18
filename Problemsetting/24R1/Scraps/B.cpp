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

void solveCase()
{
    string s;
    cin >> s;
    if(s.length() % 2 != 0)
    {
        cout << "Unhappy\n";
        return;
    }
    int vowelCnt = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            vowelCnt++;
    }
    if(vowelCnt % 2 == 0)
        cout << "Happy";
    else
        cout << "Unhappy";
    cout << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}