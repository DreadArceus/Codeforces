#include <iostream>
#include <vector>
using namespace std;
long long solve(vector<pair<int, int> > v)
{
  int minA = v[0].first, minB = v[0].second;
  for(int i = 1; i < v.size(); i++)
  {
    if(v[i].first < minA)
    {
      minA = v[i].first;
    }
    if(v[i].second < minB)
    {
      minB = v[i].second;
    }
  }
  long long moves = 0;
  for(int i = 0; i < v.size(); i++)
  {
    moves += max(v[i].first - minA, v[i].second - minB);
  }
  return moves;
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n = 0;
    cin >> n;
    vector<pair<int, int> > v(n);
    for(int i = 0; i < n; i++)
    {
      cin >> v[i].first;
    }
    for(int i = 0; i < n; i++)
    {
      cin >> v[i].second;
    }
    long long ans = solve(v);
    cout << ans << "\n";
  }
}
