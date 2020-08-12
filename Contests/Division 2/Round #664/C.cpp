//Advanced Bit Manip?
#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> a, vector<int> b)
{
  vector<int> c(a.size());
  for(int i = 0; i < a.size(); i++)
  {
    int min = 1000;
    for(int x : b)
    {
      if((x & a[i]) < min)
      {
        min = x & a[i];
      }
    }
    c[i] = min;
  }
  int ans = 0;
  for(int i = 0; i < c.size(); i++)
  {
    cout << c[i] << ":";
    ans |= c[i];
  }
  return ans;
}
int main()
{
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for(int i = 0; i < m; i++)
  {
    cin >> b[i];
  }
  int ans = solve(a, b);
  cout << ans;
}
