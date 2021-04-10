#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

int l = 0, r = 0;
set<int> solve(vector<int> nums, int target)
{
    set<set<int> > dp[target + 1];
    for (int i = 0; i <= target; i++)
    {
        dp[i] = set<set<int> >();
    }
    for (int j = 0; j < nums.size(); j++)
    {
        for (int i = 1; i <= target; i++)
        {
            set<set<int> > current = dp[i];
            if (i == nums[j])
            {
                set<int> base;
                base.insert(nums[j]);
                current.insert(base);
            }
            else if (i > nums[j])
            {
                set<set<int> > old = dp[i - nums[j]];
                set<set<int> >::iterator it = old.begin();
                while (it != old.end())
                {
                    set<int> next = *it;
                    next.insert(nums[j]);
                    current.insert(next);
                    it++;
                }
            }
           dp[i] = current;
        }
    }
    set<set<int> >::iterator it = dp[target].begin();
    while (it != dp[target].end())
    {
        if (it->size() == r - l + 1)
        {
            return *it;
        }
        it++;
    }
    return set<int>();
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {

        int n = 0, s = 0;
        cin >> n >> l >> r >> s;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            nums[i] = i + 1;
        }
        set<int> ans = solve(nums, s);
        if (ans.size() == 0)
        {
            cout << -1 << "\n";
            continue;
        }
        set<int>::iterator it = ans.begin();
        while (it != ans.end())
        {
            cout << *it << " ";
            it++;
        }
        cout << "\n";
    }
}