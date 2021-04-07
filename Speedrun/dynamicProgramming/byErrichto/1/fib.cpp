#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int fib0 = 0, fib1 = 1;
    if (n == 0)
    {
        cout << fib0;
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        fib1 = fib0 + fib1;
        fib0 = fib1 - fib0;
    }
    cout << fib1;
}