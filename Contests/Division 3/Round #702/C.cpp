#include <iostream>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        ll x = 0;
        cin >> x;
        ll crX = pow(x, 1.0/3.0);
        map<ll, int> checker;
        bool result = false;
        for(ll i = 1; i <= crX; i++)
        {
            ll cube = i*i*i;
            checker[cube] = 1;
            if(checker[x - cube] == 1)
            {
                result = true;
                break;
            }
        }
        cout << ((result) ? "YES" : "NO") << "\n";
    }
}