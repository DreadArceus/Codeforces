#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main()
{
    int n = 0, t = 0;
    string w;
    cin >> n >> t >> w;
    vector<map<char, int>> prefix(n);
    prefix[0][w[0]] = 1;
    for(int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i-1];
        prefix[i][w[i]]++;
    }
    while(t--)
    {
        int l = 0, r = 0;
        cin >> l >> r;
        char maxC = ' ';
        long long freq = 0;
        for(auto it : prefix[r - 1])
        {
            long long curr = it.second - ((l == 1) ? 0 : prefix[l-2][it.first]);
            if(freq < curr)
            {
                freq = curr;
                maxC = it.first;
            }
        }
        cout << maxC << "\n";
    }
}