#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        float x = 0;
        cin >> n >> x;
        long long min = 0, max = 0;
        for(int i = 0; i < n; i++)
        {
            int y = 0;
            cin >> y;
            min += y;
            max += ceil(y/x);
        }
        cout << ceil(min/x) << " " << max << "\n";
    }
}