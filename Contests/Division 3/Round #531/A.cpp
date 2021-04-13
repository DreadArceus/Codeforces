#include <iostream>
#include <vector>
using namespace std;
#define int long long
int32_t main()
{
    int n = 0;
    cin >> n;
    if ((n * (n+1))/2 % 2 == 0) cout << 0;
    else cout << 1;
    cout << "\n";
}