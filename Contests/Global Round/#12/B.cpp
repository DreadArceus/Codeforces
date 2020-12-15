#include <iostream>
#include <set>
#define pi pair<int, int>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, k = 0;
        cin >> n >> k;
        set<pi> balls;
        for(int i = 0; i < n; i++)
        {
            pi p;
            cin >> p.first >> p.second;
            balls.insert(p);
        }
    }
}