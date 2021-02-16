#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void recurse(vector<int> p)
{}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        vector<int> p(n);
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        recurse(p);
    }
}