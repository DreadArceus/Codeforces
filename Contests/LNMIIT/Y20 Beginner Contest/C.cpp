#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        long long a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        long long ans = 0;
        if(c > 1 && a > 0 && b > 1)
        {
            long long potB = min(c/2, b);
            ans += 3 * potB;
            b -= potB;
            c -= 2*potB;
            long long potA = min(a, b/2);
            ans += 3 * potA;
            b -= 2 * potA;
            a -= potA;
        }
        if(a > 0 && b > 1)
        {
            long long potA = min(a, b/2);
            ans += 3 * potA;
            a -= potA;
            b -= 2 * potA;
        }
        if(c > 1 && b > 0)
        {
            long long potB = min(c/2, b);
            ans += 3 * potB;
            b -= potB;
            c -= 2 * potB;
        }
        cout << ans << "\n";
    }
}