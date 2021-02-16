#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        cout << v[i] + v[i+1] << " ";
    }
    cout << v[n-1];
}