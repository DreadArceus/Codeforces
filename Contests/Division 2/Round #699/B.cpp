#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, k = 0;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int stop = -1;
        for(int i = 0; i < n - 1; i++)
        {
            if(v[i] < v[i+1])
            {
                stop = i;
                break;
            }
        }
        for(int i = 0; i < k; i++)
        {
            if(stop != 0 && v[stop] > v[stop - 1])
            {
                stop--;
            }
            else if(v[stop] >= v[stop+1])
            {
                int j = stop + 1;
                stop = -1;
                for(; j < n - 1; j++)
                {
                    if(v[j] < v[j + 1])
                    {
                        stop = j;
                        break;
                    }
                }
            }
            if(stop == -1) break;
            v[stop]++;
        }
        cout << stop + (stop != -1) << "\n";
    }
}