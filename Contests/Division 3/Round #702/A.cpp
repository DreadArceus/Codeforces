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
        int n = 0;
        cin >> n;
        int prev = -1, count = 0;
        cin >> prev;
        for(int i = 1; i < n; i++)
        {
            int x = 0;
            cin >> x;
            if(x > 2 * prev)
                count += floor(log2((x-1)/prev));
            else if(prev > 2 * x)
                count += floor(log2((prev-1)/x));
            prev = x;
        }
        cout << count << "\n";
    }
}