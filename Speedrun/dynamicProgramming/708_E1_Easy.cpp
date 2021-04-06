#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int maxA = 10000001;
vector<bool> primeCheck(maxA, true);
vector<long long> mask(maxA, 1);

int main()
{
    for (long long i = 2; i < maxA; i++)
    {
        if (!primeCheck[i])
            continue;
        for (int j = i * 2; j < maxA; j += i)
        {
            primeCheck[j] = false;
        }
        for (long long j = i; j < maxA; j += i)
        {
            long long locJ = j;
            bool odd = false;
            while(locJ % i == 0)
            {
                odd = !odd;
                locJ /= i;
            }
            if (odd)
                mask[j] *= i;
        }
    }
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0, k = 0;
        cin >> n >> k;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            int x = 0;
            cin >> x;
            v[i] = mask[x];
        }
        map<long long, bool> freq;
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (freq[v[i]])
            {
                ans++;
                freq.clear();
            }
            freq[v[i]] = 1;
        }
        cout << ans << "\n";
    }
}