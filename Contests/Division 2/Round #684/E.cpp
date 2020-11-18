//Editorial: needs segement trees... wow
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 0, q = 0;
    cin >> n >> q;
    vector<int> shops(n);
    for(int i = 0; i < n; i++)
    {
        cin >> shops[i];
    }
    while(q--)
    {
        int t = 0, x = 0, y = 0;
        cin >> t >> x >> y;
        if(t == 1)
        {
            for(int i = x - 1; i >= 0; i--)
            {
                if(y > shops[i])
                {
                    shops[i] = y;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            int cnt = 0;
            for(int i = x - 1; i < n; i++)
            {
                if(y >= shops[i])
                {
                    y -= shops[i];
                    cnt++;
                }
            }
            cout << cnt << '\n';
        }
    }
}