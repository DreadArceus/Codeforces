#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for(int i = 0; i < n - 1; i += 2)
    {
        int x = v[i] ^ v[i+1];
        if((i != n - 2 && x > v[i + 2]) || (i != 0 && x < v[i - 1]))
        {
            cout << 1;
            return 0;
        }
    }
    cout << -1;
}