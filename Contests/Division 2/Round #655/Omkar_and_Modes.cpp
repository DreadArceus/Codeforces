#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
      cout << "? " << i + 1 << " " << i + 1 << "\n";
      cout.flush();
      cin >> a[i];
      int dump;
      cin >> dump;
    }
    cout << "! ";
    for(int i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
}
//The 4k query limit makes this hard, yet to figure it out.
