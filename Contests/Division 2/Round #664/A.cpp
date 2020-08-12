//Had an unsuccessful submission because I forgot the '\n' after the output.
//Everything else is correct.
#include <iostream>
using namespace std;
bool solve(int r, int g, int b, int w)
{
  long long total = r + g + b + w;
  int zeroCount = (r == 0) + (g == 0) + (b == 0);
  if(total % 2 == 0)
  {
    if(r % 2 == 0 && g % 2 == 0 && b % 2 == 0 && w % 2 == 0)
    {
      return 1;
    }
    if(w % 2 == 0)
    {
      return 0;
    }
    else
    {
      if(r % 2 != 0 && g % 2 != 0 && b % 2 != 0)
      {
        return (zeroCount == 0);
      }
      return 0;
    }
  }
  else
  {
    if((r % 2 != 0) + (g % 2 != 0) + (b % 2 != 0) + (w % 2 != 0) == 1)
    {
      return 1;
    }
    if(w % 2 != 0 && ((r % 2 != 0) + (g % 2 != 0) + (b % 2 != 0) == 2))
    {
      return (zeroCount == 0);
    }
    else
    {
      if(r % 2 != 0 && g % 2 != 0 && b % 2 != 0)
      {
        return (zeroCount == 0);
      }
    }
  }
  return 0;
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int r = 0, g = 0, b = 0, w = 0;
    cin >> r >> g >> b >> w;
    cout << ((solve(r, g, b, w)) ? "Yes\n" : "No\n");
  }
}
