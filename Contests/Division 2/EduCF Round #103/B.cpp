#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, k = 0;
        cin >> n >> k;
        vector<double> p(n), prefix(n);
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
            if(i == 0)
            {
                prefix[i] = p[i];
            }
            else
            {
                prefix[i] = p[i] + prefix[i - 1];
            }
        }
        int max_ind = -1;
        double max = 0;
        for(int i = 1; i < n; i++)
        {
            double current = (100*p[i])/prefix[i-1];
            if(current > k && current > max)
            {
                max = current;
                max_ind = i;
            }
        }
        int min = 0;
        if(max_ind != -1)
        {
            min = ceil((100 * p[max_ind]) / k - prefix[max_ind - 1]);
        }
        cout << min << "\n";
    }
}