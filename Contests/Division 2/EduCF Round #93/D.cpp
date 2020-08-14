//Incomplete logic, still need to account for G + B pairings and used pairs
//Leaving this for now because i think G + B is going to be hard.
#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> r, vector<int> g, vector<int> b)
{
  int total = 0;
  int d = 2000, indBestArea = 0;
  for(int x : r)
  {
    for(int y : g)
    {
      int ld = abs(x - y);
      if(ld < d)
      {
        indBestArea = x * y;
        d = ld;
      }
      else if(ld == d)
      {
        int lA = x * y;
        if(lA > indBestArea)
        {
          indBestArea = lA;
        }
      }
    }
    for(int y : b)
    {
      int ld = abs(x - y);
      if(ld < d)
      {
        indBestArea = x * y;
        d = ld;
      }
      else if(ld == d)
      {
        int lA = x * y;
        if(lA > indBestArea)
        {
          indBestArea = lA;
        }
      }
    }
    total += indBestArea;
  }
  return total;
}
int main()
{
  int R = 0, G = 0, B = 0;
  cin >> R >> G >> B;
  vector<int> pR(R), pG(G), pB(B);
  for(int i = 0; i < R; i++)
  {
    cin >> pR[i];
  }
  for(int i = 0; i < G; i++)
  {
    cin >> pG[i];
  }
  for(int i = 0; i < B; i++)
  {
    cin >> pB[i];
  }
  int ans = solve(pR, pG, pB);
  cout << ans;
}
