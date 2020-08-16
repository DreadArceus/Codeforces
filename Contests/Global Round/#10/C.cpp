//Incomplete logic, apparently.
#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> v)
{
  int count = 0;
  for(int i = v.size() - 1; i > 0; i--)
  {
    if(v[i] < v[i - 1])
    {
      count += v[i - 1] - v[i];
    }
  }
  return count;
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
    int ans = solve(v);
    cout << ans << "\n";
  }
}
