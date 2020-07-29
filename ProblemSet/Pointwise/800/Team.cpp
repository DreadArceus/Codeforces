#include <iostream>
#include <vector>

using namespace std;

int countImp(vector<vector<int> > a)
{
  int cnt = 0;
  for(int i = 0; i < a.size(); i++)
  {
    if((a[i][0] == 1 && (a[i][1] == 1 || a[i][2] == 1))
      || a[i][1] == 1 && a[i][2] == 1)
    {
      cnt++;
    }
  }
  return cnt;
}

int main()
{
  int n;
  cin >> n;
  int a[n][3];

  for(int i = 0; i < a.size(); i++)
  {
    cin >> a[i][0];
    cin >> a[i][1];
    cin >> a[i][2];
  }
  int num = countImp(a);
  cout << num;
}
