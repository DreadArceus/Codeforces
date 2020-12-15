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
        vector<int> v(n);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for(int i = 0; i < (n+1)/2; i++)
        {
            cout << v[i] << " ";
            if(i != n/2 || n % 2 == 0)
            cout << v[n - i - 1] << " ";
        }
        cout << "\n";
    }
}