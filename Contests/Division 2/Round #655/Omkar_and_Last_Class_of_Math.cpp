#include <iostream>
using namespace std;
int main()
{
  int T;
  cin >> T;
  for(T; T > 0; T--)
  {
    int n;
    cin >> n;
    if(n % 2 == 0)
    {
      cout << n/2 << " " << n/2 << "\n";
    }
    else
    {
      int i = n/2 + 1, j;
      for(i; i < n; i++)
      {
        j = n - i;
        if(i % j == 0)
        {
          cout << i << " " << j << "\n";
          break;
        }
        j--;
      }
    }
  }
}
//Too slow
