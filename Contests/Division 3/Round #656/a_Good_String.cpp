//be back with recursion -17-July-2020
#include <iostream>
#include <string>
using namespace std;
bool goodChecker(string s, int n, char c)
{
  if(n > 1)
  {
    for(int i = 0; i < n/2; i++)
    {
      if(s[i] != c)
      {
        return false;
      }
    }
    goodChecker(substr(s, n/2),n/2,c+1);
  }
  if(s[0] == c)
  {
    return true;
  }
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n = 0;
    cin >> n
    string s;
    cin >> s;

  }
}
