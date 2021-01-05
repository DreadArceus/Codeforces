#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool rule(int x, int y)
{
    return x > y;
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        vector<int> v(n);
        // vector<int> even, odd;
        long long s1 = 0, s2 = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        // if(even.size() > odd.size())
        // {
        //     sort(even.begin(), even.end(), rule);
        //     for(int i = odd.size() + 1; i < even.size(); i+=2)
        //     {
        //         s1 -= even[i];
        //     }
        // }
        // else if(even.size() < odd.size())
        // {
        //     sort(odd.begin(), odd.end(), rule);
        //     for(int i = even.size(); i < odd.size(); i+=2)
        //     {
        //         s2 -= odd[i];
        //     }
        // }
        sort(v.begin(), v.end(), rule);
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
            {
                s1 += (v[i] % 2 == 0) * v[i];
            }
            else
            {
                s2 += (v[i] % 2 != 0) * v[i];
            }
        }
        if(s1 == s2)
        {
            cout << "Tie\n";
        }
        else
        {
            cout << ((s1 > s2) ? "Alice" : "Bob") << "\n";
        }
    }
}