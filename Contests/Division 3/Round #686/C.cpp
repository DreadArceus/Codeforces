#include <iostream>
#include <vector>
#include <map>
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
        map<int, int> hashMap;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            hashMap[v[i]]++;
        }
        if(hashMap.size() == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        int lF = hashMap[v[0]], rF = hashMap[v[n-1]], minF = lF;
        for(auto x : hashMap)
        {
            if (x.second < minF)
            {
                minF = x.second;
            }
        }
        if(v[0] == v[n-1] && (lF <= minF + 1))
        {
            cout << lF - 1;
        }
        else if(rF == minF || lF == minF)
        {
            cout << minF;
        }
        else
        {
            cout << minF + 1;
        }
        cout << "\n";
    }
}