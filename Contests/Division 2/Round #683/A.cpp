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
        cout << n << "\n";
        for(int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}