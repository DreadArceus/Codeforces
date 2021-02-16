#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        string x, y;
        cin >> x >> y;
        unordered_map<char, int> freq1, freq2;
        int count = x.length() + y.length();
        for(char c : x)
        {
            freq1[c]++;
        }
        for(char c : y)
        {
            freq2[c]++;
        }
        for(char c : x)
        {
            count -= 2 * min(freq2[c], freq1[c]);
            freq1[c] = 0;
            freq2[c] = 0;
        }
        if(count == 0)
        {
            cout << -1 << "\n";
            continue;
        }
        string ans = "FLAMES";
        while(ans.length() != 1)
        {
            ans.erase(ans.begin() + (count-1) % ans.length());
        }
        cout << ans << "\n";
    }
}