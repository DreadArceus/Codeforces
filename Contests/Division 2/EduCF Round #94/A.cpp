#include <iostream>
#include <string>
using namespace std;
string solve(int n, string b)
{
    string ans = "";
    ans.resize(n);
    for(int i = 0; i < ans.length(); i++)
    {
        ans[i] = b[n-1];
    }
    return ans;
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        string b;
        cin >> b;
        string ans = solve(n, b);
        cout << ans << "\n";
    }
}