#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long long solve(vector<int> inp)
{
    long long sum = 0;
    sum += 2 * min(inp[2], inp[4]);
    if(inp[1] > inp[3] && inp[5] > inp[0])
    {
        sum -= 2 * min(inp[1] - inp[3], inp[5] - inp[0]);
    }
    return sum;
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        vector<int> input(6);
        for(int i = 0; i < 6; i++)
        {
            cin >> input[i];
        }
        long long ans = solve(input);
        cout << ans << "\n";
    }
}