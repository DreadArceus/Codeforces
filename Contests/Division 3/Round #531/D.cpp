#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0;
    string s;
    cin >> n >> s;
    vector<int> numCount(3, n / 3);
    for (int i = 0; i < n; i++)
        numCount[s[i] - '0']--;
    int holdZero = n / 3;
    for (int i = 0; i < n; i++)
    {
        int currentNum = s[i] - '0';
        if (currentNum == 0 && holdZero-- > 0)
            continue;
        if (numCount[currentNum] >= 0)
            continue;
        for (int j = 0; j < 3 - (currentNum == 1); j++)
        {
            if (j == currentNum)
                continue;
            if (numCount[j] > 0)
            {
                s[i] = char('0' + j);
                numCount[j]--;
                numCount[currentNum]++;
                break;
            }
        }
    }
    for (int i = n - 1; i >= 0 && numCount[1] < 0; i--)
    {
        int currentNum = s[i] - '0';
        if (currentNum != 1)
            continue;
        s[i] = '2';
        numCount[1]++;
    }
    cout << s;
}