#include <iostream>
#include <vector>
using namespace std;
void printAnswer(int n)
{
  for(int i = 1; i <= n; i++)
  {
    cout << i << ((i != n) ? " " : "");
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
    printAnswer(n);
    cout << "\n";
  }
}
