#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int32_t main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        vector<long long> v(n + 2);
        long long sum = 0;
        for (int i = 0; i < n + 2; i++)
        {
            cin >> v[i];
            sum += v[i];
        }
        sort(v.begin(), v.end());
        bool found = false;
        for (int i = 0; i < n + 2; i++)
        {
            if ((sum - v[i]) % 2 == 0)
            {
                long long localSum = sum - v[i];
                vector<long long>::iterator it = lower_bound(v.begin(), v.end(), localSum / 2);
                if (it != v.end() && *it == localSum / 2)
                {
                    if(it == v.begin() + i)
                    {
                        it++;
                        if(it == v.end() || *it != *(v.begin() + i))
                        {
                            continue;
                        }
                    }
                    int ind = it - v.begin();
                    if(ind > i)
                    {
                        ind--;
                    }
                    v.erase(v.begin() + i);
                    v.erase(v.begin() + ind);
                    found = true;
                    break;
                }
            }
        }
        if (!found)
        {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
}