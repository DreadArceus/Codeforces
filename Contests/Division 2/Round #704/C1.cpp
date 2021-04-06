#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int l = 1, r = n, response = -1;
    int lCheck = 0;
    while(true)
    {
        cout << "? " << l << " " << r << endl;
        int newR = -1;
        cin >> newR;
        if(response == -1) response = newR;
        if(newR != response)
        {
            int dif = (r - l);
            if(lCheck)
            {
                l += (dif)/2 + 1;
                r += (dif)/2 + 1;
                lCheck = 0;
            }
            else
            {
                l -= (dif)/2 + 1;
                r -= (dif)/2 + 1;
                lCheck = 1;
            }
            // if(l == r - 1) break;
        }
        else
        {
            if(newR < (l + r) / 2)
            {
                r = (l + r) / 2;
                lCheck = 1;
            }
            else
            {
                l = (l + r) / 2;
                lCheck = 0;
            }
        }
    }
    cout << "! " << l;
}