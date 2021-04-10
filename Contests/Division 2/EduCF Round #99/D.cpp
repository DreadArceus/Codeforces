#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int spSort(vector<int> &v, int x)
{
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        bool sorted = true;
        for (int j = i; j < v.size(); j++)
            if (j != 0 && v[j - 1] > v[j])
                sorted = false;
        if (sorted)
            break;
        if (v[i] > x)
        {
            swap(v[i], x);
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0, x = 0;
        cin >> n >> x;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int cnt = spSort(v, x);

        bool sorted = true;
        for (int i = 1; i < n; i++)
        {
            if (v[i] < v[i - 1])
            {
                sorted = false;
                break;
            }
        }
        cout << (sorted ? cnt : -1) << "\n";
    }
}