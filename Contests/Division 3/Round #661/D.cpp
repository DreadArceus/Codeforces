#include <iostream>
#include <string>
using namespace std;
int split(string s)
{
  int cnt = 0;
  while(true)
  {
    pair<string, string> p = {"", ""};
    int j = 0;
    p.first += s[0];
    for(int i = 1; i < s.length(); i++)
    {
      if(s[i] != p.first[j])
      {
        p.first += s[i];
        j++;
      }
      else
      {
        p.second += s[i];
      }
    }
    cnt++;
    if(p.second == "")
    {
      break;
    }
    s = p.second;
  }
  return cnt;
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n = 0;
    cin >> n;
    string s = "";
    cin >> s;
    int ans = split(s);
    cout << ans << "\n";
  }
}
