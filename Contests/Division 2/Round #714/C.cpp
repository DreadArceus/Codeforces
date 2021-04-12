#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int maxN = 200010;
long long dp[maxN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 10; i++)
        dp[i] = 1;
    for (int i = 10; i < maxN; i++)
    {
        dp[i] = (dp[i - 9] + dp[i - 10]) % int(1e9 + 7);
    }
    int t = 0;
    cin >> t;
    while (t--)
    {
        string n;
        unsigned long long m = 0, sum = 0;
        cin >> n >> m;
        for (int i = 0; i < n.length(); i++)
        {
            sum += dp[n[i] - '0' + m] % int(1e9 + 7);
            sum %= int(1e9 + 7);
        }
        cout << sum << "\n";
    }
}