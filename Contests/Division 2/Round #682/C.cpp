#include <iostream>
#include <vector>
using namespace std;

static vector<pair<int, int>> adj = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool valid(vector<vector<int>> v, vector<vector<int>> m)
{
    for(int i = 0; i < m.size(); i++)
    {
        for(int j = 0; j < m[0].size(); j++)
        {
            for(auto z : adj)
            {
                if(((i > z.first + 1 && i > z.second + 1) || z.second > 0) &&
                    ((i < v.size() - z.first && j < v[0].size() - z.second) || z.second < 0) &&
                    v[i][j] + m[i][j] == v[i + z.first][j + z.second] + m[i + z.first][j + z.second])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<vector<int>> recurse(vector<vector<int>> v, vector<vector<int>> mod, int i, int j)
{
    for(auto z : adj)
    {
        if(((i > z.first + 1 && j > z.second + 1) || z.second > 0) &&
            ((i < v.size() - z.first && j < v[0].size() - z.second) || z.second < 0) &&
            v[i][j] + mod[i][j] == v[i + z.first][j + z.second] + mod[i + z.first][j + z.second])
        {
            vector<vector<int>> loc = mod;
            loc[i][j]++;
            loc = recurse(v, loc, ((j == v[0].size() - 1) ? 1 : 0) + i, ((j == v[0].size() - 1) ? -j : 1) + j);
            if(loc[0][0] != -2)
            {
                return loc;
            }
        }
    }
    // if(!valid(v, mod))
    // {
    //     mod[0][0] = -2;
    // }
    return mod;
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, m = 0;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
        }
        vector<vector<int>> mod(n, vector<int>(m, 0));
        mod = recurse(v, mod, 0, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout << v[i][j] + mod[i][j] << " ";
            }
            cout << "\n";
        }
    }
}