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
        int sumX = 0, sumY = 0;
        for(int i = 0; i < n; i++)
        {
            int x = 0, y = 0;
            cin >> x >> y;
            sumX += x;
            sumY += y;
        }
        cout << sumX/n << " " << sumY/n << "\n";
    }
}