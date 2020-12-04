#include <iostream>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        int wx = x - 1, wy = y;
        cout << wx << " " << wy << "\n";
    }
}