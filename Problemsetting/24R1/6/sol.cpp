#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define int long long
int32_t mod = 1e9 + 7;

void solveCase()
{
    int n = 0, target = 0;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int j = 0; j < nums.size(); j++)
        for (int i = nums[j]; i <= target; i++)
            dp[i] = (dp[i] + dp[i - nums[j]]) % mod;
    cout << dp[target];
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solveCase();
}