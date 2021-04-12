#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0, k = 0;
        cin >> n >> k;
        if(k > (n-1)/2)
        {
            cout << "-1\n";
            continue;
        }
        int maxE = n;
        for(int i = 1; i <= maxE; i++)
        {
            if(i > 1 && i < maxE && k > 0)
            {
                cout << maxE-- << " ";
                k--;
            }
            cout << i << " ";
        }
        cout << "\n";
    }
}