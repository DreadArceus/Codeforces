#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        vector<int> v(n), bl(n, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int max = 0;
        for(int i = 0; i < n; i++)
        {
            if(bl[i])
            {
                continue;
            }
            int score = 0;
            for(int j = i; j < n; )
            {
                if(bl[j]) break;
                score += v[j];
                bl[j] = 1;
                j += v[j];
            }
            if(score > max)
            {
                max = score;
            }
        }
        cout << max << '\n';
    }
}