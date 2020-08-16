//Runtime Error??
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solve(vector<int> v, int k)
{
  vector<int> local(v.size(), 0);
  int max = *max_element(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++)
  {
    local[i] = max - v[i];
  }
  v = local;
  if(k != 1 && k % 2 == 0)
  {
    max = *max_element(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
      local[i] = max - v[i];
    }
    v = local;
  }
  return v;
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
    vector<int> ans = solve(v, k);
    for(int i = 0; i < n; i++)
    {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
}
