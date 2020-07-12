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
      for(int i = 0; i < n - 1; i++)
      {
        cout << 1 << " ";
      }
      cout << 1 << "\n";
    }
}
//Correct
