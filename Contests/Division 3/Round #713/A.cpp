#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        vector<int> v(n);
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            m[v[i]]++;
        }
        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            if (m[v[i]] == 1)
            {
                ans = i;
            }
        }
        cout << ans + 1 << endl;
    }
}