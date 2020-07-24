//Incomplete Logic (case 5 in pretest 1),
//no idea whats wrong, difficult question?-24-July-2020
#include <iostream>
#include <vector>
using namespace std;
vector<int> max(int a[], int n)
{
  vector<int> ans;
  int m = -1;
  for(int i = 0; i < n; i++)
  {
    if(a[i] > m)
    {
      m = a[i];
    }
  }
  for(int i = 0; i < n; i++)
  {
    if(a[i] == m)
    {
      ans.push_back(i);
    }
  }
  return ans;
}
int depthChange(int t, int k)
{
  t = t % (2*k);
  if(t > k)
  {
    int ans = 2*k - t;
    return ans;
  }
  return t;
}
bool possible(int d[], int n, int k, int l)
{
  int t = 0;
  vector<int> maxI = max(d, n);
  if(d[maxI[0]] > l)
  {
    return false;
  }
  if(d[maxI[0]] + k <= l)
  {
    return true;
  }
  for(int z = 0; z < maxI.size(); z++)
  {
    bool good = true;
    int md = d[maxI[z]];
    while(0 == 0)
    {
      if(md + depthChange(t + maxI[z] + 1, k) == l && ((t + maxI[z] + 1) % (2*k) > k || md == l))
      {
        break;
      }
      t++;
    }
    int pos = 0;
    while(pos < n)
    {
      t++;
      if(d[pos] + depthChange(t, k) <= l)
      {
        pos++;
      }
      else
      {
        good = false;
        break;
      }
    }
    if(good)
    {
      return true;
    }
  }
  return false;
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n = 0, k = 0, l = 0;
    cin >> n >> k >> l;
    int d[n];
    for(int i = 0; i < n; i++)
    {
      cin >> d[i];
    }
    if(possible(d, n, k, l))
    {
      cout << "Yes\n";
    }
    else
    {
      cout << "No\n";
    }
  }
}
