#include <iostream>
#include <vector>
using namespace std;
int solve(vector<vector<char> > v)
{
  int n = v.size(), m = v[0].size();
  int changes = 0;
  for(int i = 0; i < m - 1; i++)
  {
    changes += (v[n - 1][i] != 'R');
  }
  for(int i = 0; i < n - 1; i++)
  {
    changes += (v[i][m - 1] != 'D');
  }
  return changes;
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<char> > grid(n);
    for(int i = 0; i < n; i++)
    {
      vector<char> loc(m);
      for(int j = 0; j < m; j++)
      {
        cin >> loc[j];
      }
      grid[i] = loc;
    }
    int ans = solve(grid);
    cout << ans << "\n";
  }
}
