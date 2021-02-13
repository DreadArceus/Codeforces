#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int px = 0, py = 0;
        string s;
        cin >> px >> py >> s;
        int u = 0, d = 0, r = 0, l = 0;
        for(char c : s)
        {
            if(c == 'U')
            {
                u++;
            }
            else if(c == 'D')
            {
                d++;
            }
            else if(c == 'R')
            {
                r++;
            }
            else if(c == 'L')
            {
                l++;
            }
        }
        cout << ((((px >= 0 && px <= r) || (px < 0 && px*-1 <= l))
            && ((py >= 0 && py <= u) || (py < 0 && py*-1 <= d))) ? "YES" : "NO") << "\n";
    }
}