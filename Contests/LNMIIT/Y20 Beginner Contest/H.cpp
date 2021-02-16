#include <iostream>
#include <vector>
using namespace std;

#define ll long long

bool primeCheck(ll x)
{
    if(x == 1)
    {
        return 0;
    }
    for(ll i = 2; i*i <= x; i++)
    {
        if(x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    ll n = 0;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll leftPrime = -1;
    for(ll i = 0; i < n; i++)
    {
        if(primeCheck(v[i]))
        {
            leftPrime = i;
            break;
        }
    }
    if(leftPrime == -1)
    {
        cout << (n * (n + 1))/2;
    }
    else
    {
        ll rightPrime = -1;
        for(ll i = n - 1; i >= 0; i--)
        {
            if(primeCheck(v[i]))
            {
                rightPrime = i;
                break;
            }
        }
        cout << (leftPrime + 1) * (n - rightPrime);
    }
}