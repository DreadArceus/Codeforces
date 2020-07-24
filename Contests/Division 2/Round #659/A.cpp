#include <iostream>
#include <string>
#include <cmath>
using namespace std;
char increment(char c)
{
  if(c == 'z')
  {
    return 'a';
  }
  return c + 1;
}
void findStrings(string s[], int a[], int n)
{
  for(int i = 1; i <= n; i++)
  {
    s[i].resize(s[0].length());
    for(int j = 0; j < a[i - 1]; j++)
    {
      s[i][j] = s[i-1][j];
    }
    for(int j = a[i - 1]; j < s[i].length(); j++)
    {
      s[i][j] = increment(s[i-1][j]);
    }
  }
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n = 0;
    cin >> n;
    int a[n];
    int m = 0;
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
      if(a[i] > m)
      {
        m = a[i];
      }
    }
    string s[n+1];
    s[0].resize(max(m,1));
    for(int j = 0; j < s[0].length(); j++)
    {
      s[0][j] = 'a';
    }
    findStrings(s, a, n);
    for(int i = 0; i <= n; i++)
    {
      cout << s[i] << "\n";
    }
  }
}
