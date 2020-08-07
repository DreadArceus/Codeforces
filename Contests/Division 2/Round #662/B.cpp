//Came up with interesting logic, think it will work, got a segmentation error x.x
//be back -7-August-2020
#include <iostream>
#include <set>
#include <string>
using namespace std;
bool possible(multiset<int> us)
{
  multiset<int> m(us);
  for(auto it : m)
  {
    bool foundSq = 0, foundRec1 = 0, foundRec2 = 0;
    int cnt = m.count(it);
    if(cnt >= 4 && !foundSq)
    {
      foundSq = true;
      m.erase(it);
    }
    else if(cnt >= 2 && !foundRec2)
    {
        foundRec2 = foundRec1 || cnt >= 4;
        foundRec1 = true;
        m.erase(m.find(it));
        m.erase(m.find(it));
    }
    else
    {
      m.erase(it);
    }
  }
  return false;
}
int main()
{
  int n = 0;
  cin >> n;
  multiset<int> us;
  for(int i = 0; i < n; i++)
  {
    int loc = 0;
    cin >> loc;
    us.insert(loc);
  }
  int q = 0;
  cin >> q;
  while(q--)
  {
    char x = 0;
    int i = 0;
    cin >> x >> i;
    if(x == '+')
    {
      us.insert(i);
    }
    else
    {
      us.erase(us.find(i));
    }
    if(possible(us))
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }
}
