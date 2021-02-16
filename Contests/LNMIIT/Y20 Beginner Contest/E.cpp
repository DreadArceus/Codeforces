#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    vector<long long> v(n);
    map<long long, int> freq;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        freq[v[i]]++;
    }
    long long maxWeight = 0, maxNum = 0, var = 0;
    for(auto it : freq)
    {
        long long currW = (it.first+1) * it.second;
        if(currW > maxWeight)
        {
            maxWeight = currW;
            maxNum = it.second;
            var = it.first;
        }
    }
    cout << maxNum << "\n";
    for(int i = 0; i < n; i++)
    {
        if(v[i] == var)
        {
            cout << i + 1 << " ";
        }
    }
}