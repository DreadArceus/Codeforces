#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    vector<int> v(n);
    map<int, int> freq;
    // int maxNum = 0, var = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        freq[v[i]]++;
        // if(freq[v[i]] > maxNum)
        // {
        //     maxNum = freq[v[i]];
        //     var = v[i];
        // }
    }
    long long maxWeight = 0, maxNum = 0, var = 0;
    for(auto it : freq)
    {
        long long currW = it.first * it.second;
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