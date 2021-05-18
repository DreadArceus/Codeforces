#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t mod = 1e9 + 7;

void solveCase()
{
    int n = 0, q = 0;
    string s;
    cin >> n >> s >> q;
    vector<int> prefix(n);
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (i != 0)
            prefix[i] = prefix[i - 1];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            prefix[i] += 1;
    }
    while (q--)
    {
        int type = 0;
        cin >> type;
        if (type == 1)
        {
            int l = 0, r = 0;
            cin >> l >> r;
            l--;
            r--;
            cout << prefix[r] - (l != 0 ? prefix[l - 1] : 0) << endl;
        }
        else
        {
            int i = 0;
            char c;
            cin >> i >> c;
            i--;
            bool f = s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u';
            if (!f)
            {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    for (int x = i; x < n; x++)
                        prefix[x]++;
            }
            else
            {
                if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
                    for (int x = i; x < n; x++)
                        prefix[x]--;
            }
            s[i] = c;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solveCase();
}