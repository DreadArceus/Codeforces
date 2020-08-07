#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int solve(vector <int> v)
{
  unordered_map<int, int> m;
  int max = 0;
  for(int sum = 2; sum <= 100; sum++)
  {
    vector<int> local(v);
    for(int i = 0; i < v.size(); i++)
    {
      if(!local[i])
      {
        continue;
      }
      for(int j = i + 1; j < v.size(); j++)
      {
        if(!local[j])
        {
          continue;
        }
        if(v[i]+v[j] == sum)
        {
          m[sum]++;
          if(m[sum] > m[max])
          {
            max = sum;
          }
          local[j] = 0;
          break;
        }
      }
    }
  }
  return m[max];
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
    for(int i = 0; i < v.size(); i++)
    {
      cin >> v[i];
    }
    int k = solve(v);
    cout << k << "\n";
  }
}
