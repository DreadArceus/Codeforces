#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
            cout << 'a';
        return 0;
    }
    int x = 0, y = 1;
    cout << 'a';
    for (int i = 1; i < n;)
    {
        cout << char('a' + x);
        i++;
        if (i == n)
            break;
        if (!(i == n - 1 && n % 2 == 1))
        {
            cout << char('a' + y);
            y++;
            i++;
        }
        if (i == n)
            break;
        if (y >= k)
        {
            x++;
            y = x + 1;
            cout << char('a' + x);
            i++;
        }
        if (i == n)
            break;
        if (y >= k)
        {
            cout << 'a';
            i++;
            x = 0;
            y = 1;
        }
        if (i == n)
            break;
    }
}