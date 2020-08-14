#include <iostream>
#include <vector>
using namespace std;
void printAnswer(vector<int> v)
{
  // Faster Logic:
  if(v[v.size() - 1] >= v[0] + v[1])
  {
    cout << 1 << " " << 2 << " " << v.size();
  }
  else
  {
    cout << -1;
  }
  // The following is a solution that works with unoredered numbers
  // Doesn't matter though, sorting it is easier than this, probably.
  // for(int i = 0; i < v.size() - 2; i++)
  // {
  //   while(i > 0 && v[i-1] == v[i] && i > v.size() - 3)
  //   {
  //     i++;
  //   }
  //   for(int j = i + 1; j < v.size() - 1; j++)
  //   {
  //     while(j > i + 1 && v[j-1] == v[j] && j > v.size() - 2)
  //     {
  //       j++;
  //     }
  //     int k = j + 1;
  //     while(k < v.size() && v[k] == v[k - 1])
  //     {
  //       k++;
  //     }
  //     if(v[k] >= v[j] + v[i])
  //     {
  //       cout << i  + 1 << " " << j + 1 << " " << k + 1;
  //       return;
  //     }
  //   }
  // }
  // cout << -1;
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
    printAnswer(v);
    cout << "\n";
  }
}
