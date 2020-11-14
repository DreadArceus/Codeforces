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
        int ar[n];
        map<int, int> hashMap;
        bool wrg = false;
        for(int i = 0; i < n; i++)
        {
            cin >> ar[i];
            hashMap[ar[i]]++;
            if(hashMap[ar[i]] > 1)
            {
                wrg = true;
            }
        }
        cout << ((wrg) ? "YES" : "NO") << "\n";
    }
}