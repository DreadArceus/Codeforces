#include <iostream>
#include <string>
using namespace std;
char adv(char c)
{
  if(c == 'R')
  {
    return 'P';
  }
  if(c == 'P')
  {
    return 'S';
  }
  return 'R';
}
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    string s;
    cin >> s;
    string ans;
    for(int i = 0; i < s.length(); i++)
    {
      ans.push_back(adv(s[i]));
    }
    cout << "The result is: " << ans << "\n";
  }
}
//The algorithm seems complicated
