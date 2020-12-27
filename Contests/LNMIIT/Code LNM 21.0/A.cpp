#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        ll n = 0;
        cin >> n;
        string ans = "Bob";
        for(ll i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                ans = "Alice";
            }
        }
        cout << ans << "\n";
    }
}