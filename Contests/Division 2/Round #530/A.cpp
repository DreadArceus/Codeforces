#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int w = 0, h = 0, u1 = 0, u2 = 0, d1 = 0, d2 = 0;
    cin >> w >> h >> u1 >> d1 >> u2 >> d2;
    if(d2 > d1)
    {
        swap(d2, d1);
        swap(u1, u2);
    }
    int finalW = w;
    while(h >= d1)
    {
        finalW += h--;
    }
    finalW = max(0, finalW - u1);
    while(h >= d2)
    {
        finalW += h--;
    }
    finalW = max(0, finalW - u2);
    while(h > 0)
    {
        finalW += h--;
    }
    cout << finalW << "\n";
}