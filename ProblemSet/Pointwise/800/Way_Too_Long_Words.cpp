#include <iostream>
#include <string>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for(T; T > 0; T--)
  {
    string x;
    cin >> x;
    if(x.length() > 10)
    {
      cout << x[0] << x.length() - 2 << x[x.length() - 1] << "\n";
    }
    else
    {
      cout << x << "\n";
    }
  }
  return 0;
}
