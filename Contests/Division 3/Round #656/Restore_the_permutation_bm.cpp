#include <iostream>
#include <vector>
using namespace std;
vector<int> ogPerm(int a[], int n)
{
  vector<int> ans;
  bool unique = true;
  for(int i = 0; i < 2 * n; i++)
  {
    for(int j = 0; j < ans.size(); j++)
    {
      if(a[i] == ans[j])
      {
        unique = false;
      }
    }
    if(unique)
    {
      ans.push_back(a[i]);
    }
    unique = true;
  }
  return ans;
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n = 0;
    cin >> n;
    int a[2 * n];
    for(int i = 0; i < 2 * n; i++)
    {
      cin >> a[i];
    }
    vector<int> p = ogPerm(a, n);
    for(int i = 0; i < p.size(); i++)
    {
      cout << p[i] << " ";
    }
    cout << "\n";
  }
}
