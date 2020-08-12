//Did the ordering of the position wrong, and then the contest ended
//This is correct tho
#include <iostream>
using namespace std;
void printNew(pair<int, int> pos)
{
  cout << pos.second << " " << pos.first << "\n";
}
void printMovements(int x, int y, int n, int m)
{
  pair<int, int> pos = {x, y};
  while(pos.first != m + 1)
  {
    if(pos.second == y || pos.second == n)
    {
      while(pos.second != 1)
      {
        pos.second--;
        printNew(pos);
      }
    }
    else
    {
      while(pos.second != n)
      {
        pos.second++;
        printNew(pos);
      }
    }
    if(pos.first == x)
    {
      pos.second = y + 1;
      printNew(pos);
      while(pos.second != n)
      {
        pos.second++;
        printNew(pos);
      }
    }
    if(pos.first == 1)
    {
      pos.first = x + 1;
    }
    else if(pos.first <= x)
    {
      pos.first--;
    }
    else
    {
      pos.first++;
    }
    if(pos.first <= m)
    {
      printNew(pos);
    }
  }
}
int main()
{
  int n = 0, m = 0, x = 0, y = 0;
  cin >> n >> m >> x >> y;
  cout << x << " " << y << "\n";
  printMovements(x, y, n, m);
}
