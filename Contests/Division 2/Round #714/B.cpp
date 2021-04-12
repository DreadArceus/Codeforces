#include <iostream>
#include <vector>
#include <map>
using namespace std;

unsigned long long fact(unsigned long long x)
{
    unsigned long long ans = x;
    while (--x)
    {
        ans = (ans * x) % int(1e9 + 7);
    }
    return ans;
}

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
        map<int, int> andMap;
        int totalAnd = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            m[v[i]]++;
            if (i == 0)
                totalAnd = v[i];
            else
            {
                totalAnd &= v[i];
                andMap[v[i] & v[i - 1]]++;
            }
        }
        if (andMap.size() > 1)
        {
            cout << "0\n";
            continue;
        }
        if (m.size() == 1)
        {
            cout << fact(n) % int(1e9 + 7) << "\n";
            continue;
        }
        map<int, int>::iterator it = andMap.begin();
        if (totalAnd == it->first && m[it->first] > 1)
        {
            cout << (fact(n - 2) * fact(m[it->first])) % int(1e9 + 7) << "\n";
            continue;
        }
        cout << "0\n";
    }
}