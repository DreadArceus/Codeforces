#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, q = 0;
    cin >> n >> q;
    vector<int> v(n);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(m[v[i]] == 0)
            m[v[i]] = i + 1;
    }
    while(q--)
    {
        int x = 0;
        cin >> x;
        int i = m[x];
        map<int, int>::iterator it = m.begin();
        while(it != m.end())
        {
            if (it->second < i)
                it->second++;
            it++;
        }
        m[x] = 1;
        cout << i << " ";
    }
}