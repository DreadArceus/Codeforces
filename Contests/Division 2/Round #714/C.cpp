#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 0;
    cin >> t;
    while (t--)
    {
        string n;
        int m = 0;
        cin >> n >> m;
        vector<long long> v(10, 0);
        for(int i = 0; i < n.length(); i++)
        {
            v[n[i] - '0']++;
        }
        int cycle = 0;
        while(m--)
        {
            vector<long long> temp(10);
            for(int i = 1; i < 10; i++)
            {
                temp[i] = v[i-1];
            }
            temp[0] = v[9];
            temp[1] += v[9] % int(1e9+7);
            temp[1] %= int(1e9+7);
            v = temp;
        }
        unsigned long long sum = 0;
        for(int i = 0; i < 10; i++)
        {
            sum += v[i] % int(1e9+7);
            sum %= int(1e9+7);
        }
        cout << sum << "\n";
    }
}