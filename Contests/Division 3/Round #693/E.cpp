#include <iostream>
#include <vector>
using namespace std;
#define pii pair<int, int>
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        vector<pii> v(n);
        int combo1 = INT32_MAX, combo2 = INT32_MAX, j = 0;
        int h_min = INT32_MAX, wx = INT32_MAX, j1 = 0;
        int hx = INT32_MAX, w_min = INT32_MAX, j2 = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i].first >> v[i].second;
            if(v[i].first <= combo1 && v[i].second <= combo2)
            {
                combo1 = v[i].first;
                combo2 = v[i].second;
                j = i;
            }
            if(v[i].first < h_min || (v[i].first == h_min && v[i].second < wx))
            {
                h_min = v[i].first;
                wx = v[i].second;
                j1 = i;
            }
            if(v[i].second < w_min || (v[i].second == w_min && v[i].first < hx))
            {
                w_min = v[i].second;
                hx = v[i].first;
                j2 = i;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if((v[i].first > combo1 && v[i].second > combo2) ||
                (v[i].second > combo1 && v[i].first > combo2))
            {
                cout << j + 1 << " ";
            }
            else if((v[i].first > h_min && v[i].second > wx) ||
                (v[i].second > h_min && v[i].first > wx))
            {
                cout << j1 + 1 << " ";
            }
            else if((v[i].first > hx && v[i].second > w_min) ||
                (v[i].second > hx && v[i].first > w_min))
            {
                cout << j2 + 1 << " ";
            }
            else
            {
                cout << -1 << " ";
            }
        }
        cout << "\n";
    }
}