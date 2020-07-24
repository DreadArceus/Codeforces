#include <iostream>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    int a[n];
    int j = 0, k = 0, i = 0;
    for(int x = 0; x < n; x++)
    {
      cin >> a[x];
      if(a[x] > a[j])
      {
        j = x;
      }
    }
    bool possible = false;
    for(k = j + 1; k < n; k++)
    {
        if(a[k] < a[j])
        {
          possible = true;
          break;
        }
    }
    if(!possible)
    {
      cout << "No\n";
    }
    else
    {
      possible = false;
      for(i = 0; i < j; i++)
      {
        if(a[i] < a[j])
        {
          possible = true;
          break;
        }
      }
      if(!possible)
      {
        cout << "No\n";
      }
      else
      {
        cout << "Yes\n" << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
      }
    }
  }
}
//Wrong answer in test 2 :(
