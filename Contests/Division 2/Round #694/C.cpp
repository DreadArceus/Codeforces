#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, m = 0;
        cin >> n >> m;
        vector<int> v1(n), v2(m);
        for(int i = 0; i < n; i++)
        {
            cin >> v1[i];
        }
        for(int i = 0; i < m; i++)
        {
            cin >> v2[i];
        }
    }
}