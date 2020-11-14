#include <iostream>
using namespace std;
int solve(int x, int d)
{
    //x - y - y = x - 2y = d => y = (x - d) / 2
    if(x < d)
    {
        return d - x;
    }
    if(abs(x-d) != 1 && abs(x-d)%2 == 0)
    {
        return 0;
    }
    return 1;
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, k = 0;
        cin >> n >> k;
        int ans = solve(n, k);
        cout << ans << "\n";
    }
}