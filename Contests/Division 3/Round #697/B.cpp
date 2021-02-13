#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        int x = n / 2020, y = n % 2020;
        cout << ((x >= y) ? "YES" : "NO") << "\n";
    }
}