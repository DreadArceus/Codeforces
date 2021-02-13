#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        long long n = 0;
        cin >> n;
        while(n % 2 == 0){
            n /= 2;
        }
        cout << ((n != 1) ? "YES" : "NO") << "\n";
    }
}