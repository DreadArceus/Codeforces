#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool cmp(pair<set<int>, int> a, pair<set<int>, int> b)
{
    return a.first.size() < b.first.size();
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0, x = 0;
        cin >> n >> x;
        vector<pair<set<int>, int> > v(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            v[i].second = i;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int y = 0, z = 0;
            cin >> y >> z;
            v[y].first.insert(z);
            v[z].first.insert(y);
        }
        if (v[x].first.size() <= 1)
        {
            cout << "Ayush\n";
            continue;
        }
        sort(v.begin(), v.end(), cmp);
        int dp[n + 1];
        cout << ((dp[x] % 2 == 0) ? "Ashish" : "Ayush") << "\n";
    }
}