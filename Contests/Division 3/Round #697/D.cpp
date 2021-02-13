#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define pii pair<int, int>

bool sp(pii x, pii y){
    if(y.first == 2)
    {
        if(x.first == 2)
        {
            return x.second/sqrt(2) > y.second/sqrt(2);
        }
        return x.second > y.second/sqrt(2);
    }
    else if(x.first==2)
    {
        return x.second/sqrt(2) >= y.second;
    }
    return x.second > y.second;
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, m = 0;
        cin >> n >> m;
        vector<int> a(n);
        vector<pii> b(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++)
        {
            int x = 0;
            cin >> x;
            b[i] = make_pair(x, a[i]);
        }
        sort(b.begin(), b.end(), sp);
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            m -= b[i].second;
            sum += b[i].first;
            if(m <= 0)
            {
                break;
            }
        }
        cout << ((m <= 0) ? sum : -1) << "\n";
    }
}