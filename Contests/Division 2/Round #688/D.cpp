#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int k = 0;
        cin >> k;
        int sum = 2, lastCP = 0;
        vector<int> prefixSum = {2};
        vector<int> game = {1};
        while(sum != k)
        {

            prefixSum.push_back(2 + *prefixSum.cend() + 
                ((prefixSum.size() > 1) ? *(prefixSum.cend() - 1) : 0));
        }
        cout << game.size() << "\n";
        for(int x : game)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}