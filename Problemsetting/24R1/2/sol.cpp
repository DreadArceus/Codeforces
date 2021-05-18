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
    int n = 0;
    string s;
    cin >> n >> s;
    int arr[26];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < n; i++)
        arr[s[i] - 'a']++;
    char maxLetter;
    int maxFreq = 0;
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] > maxFreq)
        {
            maxFreq = arr[i];
            maxLetter = char('a' + i);
        }
    }
    cout << maxLetter << " " << maxFreq << "\n";
}

int32_t main()
{
    solveCase();
}