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
        vector<int> v(n);
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            if(v[i] == 1) cnt1++;
            if(v[i] == 2) cnt2++;
            if(v[i] == 3) cnt3++;
        }
        cout << cnt1 + cnt3;
        cout << "\n";
    }
}