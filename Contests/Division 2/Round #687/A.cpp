#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        long long n = 0, m = 0, r = 0, c = 0;
        cin >> n >> m >> r >> c;
        long long ans = max(r-1, n-r) + max(c-1, m-c);
        cout << ans << "\n";
    }
}