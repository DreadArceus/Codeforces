#include <iostream>
#include <vector>
#include <map>
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
    int len = n;
    while(len > 0)
    {
        map<int, int> fLoc;
        for(int i = 0; i < len; i++)
        {
            fLoc[v[i]]++;
        }
        for(int i = len - 1; i < n; i++)
        {
            if(i != len - 1)
            {
                fLoc[v[i]]++;
                fLoc[v[i - len]]--;
            }
            int f1 = 0, eleF1 = 0;
            for(auto x : fLoc)
            {
                if(x.second >= f1)
                {
                    eleF1 = x.first;
                    f1 = x.second;
                }
            }
            for(auto x : fLoc)
            {
                if(x.second == f1 && x.first != eleF1)
                {
                    cout << len;
                    return 0;
                }
            }
        }
        len--;
    }
    cout << 0;
}