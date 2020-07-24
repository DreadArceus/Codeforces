#include <iostream>
using namespace std;
int manaSpent(int n, int m, int x, int y, int k)
{
  int kills = n - m, mana = -1;
  if(x <= y * k)
  {
    int fProcs = kills / k;
    mana = fProcs * x + (kills - fProcs * k) * y;
  }
  return mana;
}
int main()
{
  int n, m, x, k, y;
  cin >> n >> m >> x >> k >> y;
  int a[n], b[m];
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for(int i = 0; i < m; i++)
  {
    cin >> b[i];
  }
  int ans = manaSpent(n, m, x, y, k);
  cout << ans;
}
//There are many cases:
//Berserk being more efficient than fireball and being viable
//Fireball being better but warriors not being consecutive 100%
//I only covered the case where fireball is better and viable
