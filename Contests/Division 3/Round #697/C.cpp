#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int a = 0, b = 0, n = 0;
        cin >> a >> b >> n;
        vector<int> v(n);
        map<int, int> prefixA, prefixB;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            int x = 0;
            cin >> x;
            v[i] = x;
            prefixA[v[i]]++;
            if(prefixA[v[i]] > 1){
                cnt += ((prefixA[v[i]] - 1) * prefixA[v[i]])/2;
            }
        }
        for(int i = 0; i < n; i++)
        {
            int x = 0;
            cin >> x;
            v[i] = x;
            prefixB[v[i]]++;
            if(prefixB[v[i]] > 1){
                cnt += ((prefixB[v[i]] - 1) * prefixB[v[i]])/2;
            }
        }
        cout << ((n-1)*n)/2 - cnt << "\n";
    }
}