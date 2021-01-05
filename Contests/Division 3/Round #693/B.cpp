#include <iostream>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        int c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++)
        {
            int x = 0;
            cin >> x;
            if(x == 1)
            {
                c1++;
            }
            else
            {
                c2++;
            }
        }
        cout << (((c1 > 0 && c1 % 2 == 0) || (c1 == 0 && c2 % 2 == 0)) ? "YES" : "NO") << "\n";
    }
}