#include <iostream>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int w = 0, h = 0, n = 0;
        cin >> w >> h >> n;
        int cntW = 1;
        while(w % 2 == 0)
        {
            w /= 2;
            cntW *= 2;
        }
        int cntH = 1;
        while(h % 2 == 0)
        {
            h /= 2;
            cntH *= 2;
        }
        cout << ((cntH * cntW >= n) ? "YES" : "NO") << "\n";
    }
}