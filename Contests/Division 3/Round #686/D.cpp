#include <iostream>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        long long n = 0;
        cin >> n;
        long long firstDiv = 0;
        for(long long i = 2; i <= n/2; i++)
        {
            if(n % i == 0)
            {
                firstDiv = i;
                break;
            }
        }
        if(firstDiv)
        {
            int num = 0;
            while(n % firstDiv == 0)
            {
                num++;
                n /= firstDiv;
            }
            n *= firstDiv;
            cout << num << "\n";
            for(int i = 0; i < num - 1; i++)
            {
                cout << firstDiv << " ";
            }
        }
        else
        {
            cout << 1 << "\n";
        }
        cout << n << "\n";
    }
}