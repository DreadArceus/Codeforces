#include <iostream>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        long long x = 0;
        cin >> x;
        long long ans = 0;
        for(long long i = 0; ; i++)
        {
            if(x <= (i*(i+1))/2)
            {
                ans = i;
                break;
            }
        }
        cout << ans + ((ans*(ans+1))/2 - x == 1) << '\n';
    }
}