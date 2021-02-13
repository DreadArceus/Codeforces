#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        double n = 0, k = 0;
        cin >> n >> k;
        if(k < n)
        {
            k *= ceil(n/k);
        }
        cout << ceil(k/n) << "\n";
    }
}