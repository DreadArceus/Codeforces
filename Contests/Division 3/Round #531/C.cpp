#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 0, x = 0, y = 0;
    cin >> n >> x >> y;
    vector<int> a(n);
    int cntWeak = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= x)
            cntWeak++;
    }
    if (x > y)
    {
        cout << n << "\n";
        return 0;
    }
    cout << (cntWeak + 1)/2 << "\n";
}