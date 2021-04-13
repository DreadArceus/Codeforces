#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> v(n, 0), ans(n, 0);
    map<int, int> m;
    map<int, set<int> > done;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]]++;
    }

    map<int, int>::iterator it = m.begin();
    while (it != m.end())
    {
        if (it->second > k)
        {
            cout << "NO";
            return 0;
        }
        it++;
    }

    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if (c > k)
            c = 1;
        if (m[v[i]] > 0)
        {
            ans[i] = c;
            done[v[i]].insert(c);
            m[v[i]] = -1;
            c++;
        }
        else
        {
            int locC = c;
            while (done[v[i]].find(locC) != done[v[i]].end())
            {
                locC++;
            }
            if (locC > k)
            {
                locC = 1;
                while (done[v[i]].find(locC) != done[v[i]].end())
                {
                    locC++;
                }
            }
            ans[i] = locC;
            done[v[i]].insert(locC);
            if(locC == c) c++;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}