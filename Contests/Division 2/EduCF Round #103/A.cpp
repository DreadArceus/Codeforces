#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        long long n = 0, k = 0;
        cin >> n >> k;
        if(k < n)
        {
            k *= (n+k-1)/k;
        }
        cout << (k+n-1)/n << "\n";
    }
}