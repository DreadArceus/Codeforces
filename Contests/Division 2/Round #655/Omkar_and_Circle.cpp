#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  if(n == 1)
  {
    cout << a[0];
    return 0;
  }
  long max = a[0] + a[n - 1];
  for(int i = 0; i < n - 1; i++)
  {
    long local = a[i] + a[i + 1];
    if(local > max)
    {
      max = local;
    }
  }
  cout << max;
}
//Combining sums makes this harder.
