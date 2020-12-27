#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n = 0, t = 0;
    cin >> n >> t;
    int ans = 0;
    vector<int> v(n);
    unordered_map<int, int> hashM;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        ans ^= v[i];
        hashM[v[i]]++;
    }
    while(t--)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        if(hashM[a] % 2 != 0)
        {
            ans ^= a ^ b;
        }
        hashM[b] += hashM[a];
        hashM[a] = 0;
        cout << ans << "\n";
    }
}