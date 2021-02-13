#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, x = 0;
        cin >> n >> x;
        int minp = INT32_MAX, mini;
        long long sum = 0;
        vector<int> v(n);
        vector<long long> prefix(n, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
            if(i == 0)
            {
                prefix[0] = v[i];
            }
            else
            {
                prefix[i] = prefix[i-1] + v[i];
            }
            int a = 0;
            while(a < minp && v[i] % x == 0)
            {
                v[i] /= x;
                a++;
            }
            if(a < minp)
            {
                minp = a;
                mini = i;
            }
        }
        sum *= minp + 1;
        cout << sum + ((mini == 0) ? 0 : prefix[mini-1]) << "\n";
    }
}