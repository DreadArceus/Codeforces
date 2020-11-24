#include <iostream>
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
        map<int, pair<int, int>> hashMap;
        for(int i = 0; i < n; i++)
        {
            int x = 0;
            cin >> x;
            hashMap[x].first++;
            hashMap[x].second = i;
        }
        bool none = true;
        for(auto x : hashMap)
        {
            if(x.second.first == 1)
            {
                cout << x.second.second + 1 << "\n";
                none = false;
                break;
            }
        }
        if(none)
        {
            cout << -1 << "\n";
        }
    }
}