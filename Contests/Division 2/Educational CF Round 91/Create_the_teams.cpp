#include <bits/stdc++.h>
using namespace std;
int maxTeams(int a[], int n, int x)
{
  int cnt = 0, p = 0;
  sort(a, a + n);
  for(int i = n - 1; i >= 0; i--)
  {
    if(a[i] >= x)
    {
      cnt++;
    }
    else
    {
      p++;
      if(a[i] * p >= x)
      {
        cnt++;
        p = 0;
      }
    }
  }
  return cnt;
}
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    int ans = maxTeams(a, n, x);
    cout << ans << "\n";
  }
}
