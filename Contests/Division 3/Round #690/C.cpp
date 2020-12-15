#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int x = 0;
        cin >> x;
        if(x > 45)
        {
            cout << -1 << "\n";
            continue;
        }
        string ans = "";
        int sum = 0, i = 9;
        while(sum + i < x)
        {
            sum += i;
            ans.insert(ans.begin(), i + '0');
            i--;
        }
        if(sum != x)
            ans.insert(ans.begin(), x - sum + '0');
        cout << ans << "\n";
    }
}