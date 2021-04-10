#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        vector<string> v(n);
        vector<pair<int, int> > pos;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == '*')
                {
                    pos.push_back(make_pair(i, j));
                }
            }
        }
        if (pos[0].first == pos[1].first)
        {
            if (pos[0].first != 0)
            {
                v[pos[0].first - 1][pos[0].second] = '*';
                v[pos[0].first - 1][pos[1].second] = '*';
            }
            else
            {
                v[pos[0].first + 1][pos[0].second] = '*';
                v[pos[0].first + 1][pos[1].second] = '*';
            }
        }
        else if (pos[0].second == pos[1].second)
        {
            if (pos[0].second != 0)
            {
                v[pos[0].first][pos[0].second - 1] = '*';
                v[pos[1].first][pos[0].second - 1] = '*';
            }
            else
            {
                v[pos[0].first][pos[0].second + 1] = '*';
                v[pos[1].first][pos[0].second + 1] = '*';
            }
        }
        else
        {
            v[pos[0].first][pos[1].second] = '*';
            v[pos[1].first][pos[0].second] = '*';
        }

        for (int i = 0; i < n; i++)
        {
            cout << v[i] << "\n";
        }
    }
}