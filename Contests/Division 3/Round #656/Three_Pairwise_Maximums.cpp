#include <iostream>
#include <vector>
using namespace std;
vector<int> pairwiseMax(int x, int y, int z)
{
  if((x != y && y != z && x != z)
    || (x < y && x == z) || (x < z && x == y) || (z < x && z == y))
  {
    cout << "NO";
    vector<int> null(0);
    return null;
  }
  cout << "YES\n";
  vector<int> ans(3);
  if(x == z)
  {
    ans[0] = x;
    ans[1] = y;
    ans[2] = 1;
    return ans;
  }
  if(x == y)
  {
    ans[0] = x;
    ans[1] = z;
    ans[2] = 1;
    return ans;
  }
  ans[0] = y;
  ans[1] = x;
  ans[2] = 1;
  return ans;
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int x = 0, y = 0, z = 0;
    cin >> x >> y >> z;
    vector<int> v = pairwiseMax(x, y, z);
    for(int i = 0; i < v.size(); i++)
    {
      cout << v[i] << " ";
    }
    cout << "\n";
  }
}
