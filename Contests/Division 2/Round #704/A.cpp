#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        long long sum = 0;
        bool f = true;
        for(int i = 0; i < n; i++)
        {
            long long x = 0;
            cin >> x;
            sum += x;
            if(sum < (i * (i + 1)) / 2)
            {
                f = false;
            }
        }
        cout << (f ? "YES" : "NO") << "\n";
    }
}