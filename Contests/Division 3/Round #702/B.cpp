#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        vector<int> p(n);
        vector<int> c(3, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
            c[p[i] % 3]++;
        }
        int minC = 100000, maxC = -1, minI = -1, maxI = -1;
        for(int i = 0; i < 3; i++)
        {
            if(c[i] > maxC)
            {
                maxC = c[i];
                maxI = i;
            }
            if(c[i] < minC)
            {
                minC = c[i];
                minI = i;
            }
        }
        if(maxI - minI == 2 || (maxI - minI) == -1)
        {
            cout << (maxC - minC);
        }
        else if((maxI - minI) == 1 || maxI - minI == -2)
        {
            cout << 2 * (maxC - minC);
        }
        else
        {
            cout << 0;
        }
        cout << "\n";
    }
}