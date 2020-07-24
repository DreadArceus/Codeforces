#include <iostream>
using namespace std;
void determineWinner(int a[], int n)
{
  for(int i = 0; i < n; i++)
  {
    if(a[i] > 1)
    {
      if(i == 0 || (i+1) % 2 != 0)
      {
        cout << "First\n";
      }
      else
      {
        cout << "Second\n";
      }
      return;
    }
  }
  if(n == 1 || n % 2 != 0)
  {
    cout << "First\n";
  }
  else
  {
    cout << "Second\n";
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
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    determineWinner(a, n);
  }
}
