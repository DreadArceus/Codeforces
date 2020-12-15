#include <iostream>
#include <set>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, m = 0;
        cin >> n >> m;
        set<int> v;
        for(int i = 0; i < n; i++)
        {
            int x = 0;
            cin >> x;
            v.insert(x);
        }
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            int x = 0;
            cin >> x;
            if(v.find(x) != v.end())
            {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}