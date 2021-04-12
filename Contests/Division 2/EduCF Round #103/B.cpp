#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define int long long

int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0, k = 0;
        cin >> n >> k;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        int ans = 0;
        int sum = p[0];
        for (int i = 1; i < n; i++)
        {
            int current = (100 * p[i] + sum - 1) / sum;
            if(current > k)
            {
                ans = max(ans, (100 * p[i] + k - 1) / k - sum);
            }
            sum += p[i];
        }
        cout << ans << "\n";
    }
}