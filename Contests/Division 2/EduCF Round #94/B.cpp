#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int p = 0, f = 0, cS = 0, cW = 0, weightS = 0, weightW = 0;
        cin >> p >> f >> cS >> cW >> weightS >> weightW;
        int ans = 0;
        while(1)
        {
            if(weightS >= weightW && cS > 0)
            {
                cS--;
                p -= weightS;
                ans++;
                if(p == 0)
                    break;
            }
            else if(p >= weightW)
            {
                cW--;
                p -= weightW;
                ans++;
                if(p < weightW || cW == 0)
                    break;
            }
            else
            {
                break;
            }
            
        }
        while(1)
        {
            if(weightS >= weightW && cS > 0)
            {
                cS--;
                f -= weightS;
                ans++;
                if(f == 0)
                    break;
            }
            else if(p >= weightW)
            {
                cW--;
                f -= weightW;
                ans++;
                if(f < weightW || cW == 0)
                    break;
            }
            else
            {
                break;
            }
            
        }
        cout << ans << "\n";
    }
}