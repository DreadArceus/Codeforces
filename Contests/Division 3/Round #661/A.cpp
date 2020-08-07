#include <iostream>
#include <set>
using namespace std;
bool solve(set<int> sx)
{
  if(sx.size() == 1)
  {
    return 1;
  }
  int sum = 0, max = 0, min = *sx.begin();
  for(auto i : sx)
  {
    sum += i;
    if(i > max)
    {
      max = i;
    }
    if(i < min)
    {
      min = i;
    }
  }
  return sum == (max * (max + 1)) / 2 - (min*(min - 1)) / 2;
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n = 0;
    cin >> n;
    set<int> sx;
    for(int i = 0; i < n; i++)
    {
      int l = 0;
      cin >> l;
      sx.insert(l);
    }
    cout << (solve(sx) ? "YES\n" : "NO\n");
  }
}
