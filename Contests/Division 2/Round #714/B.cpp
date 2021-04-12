#include <iostream>
#include <vector>
#include <map>
using namespace std;

unsigned long long fact(unsigned long long x)
{
    unsigned long long ans = 1;
    for(unsigned long long i = 2; i <= x; i++)
    {
        ans = (ans * i) % int(1e9 + 7);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        vector<int> v(n);
        int totalAnd = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (i == 0)
                totalAnd = v[i];
            else
                totalAnd &= v[i];
        }
        int cntZero = 0;
        for (int i = 0; i < n; i++)
        {
            v[i] -= totalAnd;
            if(v[i] == 0)
                cntZero++;
        }
        if (cntZero > 1)
        {
            cout << (fact(n - 2) * cntZero * (cntZero - 1)) % int(1e9 + 7) << "\n";
            continue;
        }
        cout << "0\n";
    }
}