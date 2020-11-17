#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, k = 0;
        cin >> n >> k;
        vector<int> v(n * k);
        for(int i = 0; i < n * k; i++)
        {
            cin >> v[i];
        }
        long long sum = 0;
        int leave = ((n - 1) / 2) * k;
        for(int i = leave; i < v.size(); i += n - leave/k)
        {
            sum += v[i];
        }
        cout << sum << "\n";
    }
}