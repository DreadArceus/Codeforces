#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define int long long
int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        int z = pow(10, c);
        int x = 1;
        while(to_string(x).length() < a - c + 1){
            x *= 9;
        }
        int y = 1;
        while(to_string(y).length() < b - c + 1){
            y *= 10;
        }
        x *= pow(10, c-1);
        y *= pow(10, c-1);
        cout << x << " " << y << "\n";
    }
}