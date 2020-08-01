#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> solve(int n)
{
  vector<int> ans(5);
  if(n < 31)
  {
    ans[4] = 1;
    return ans;
  }
  ans[0] = 2 * 3;
  ans[1] = 2 * 5;
  ans[2] = 2 * 7;
  if(n == 36)
  {
    ans[2] = 3 * 5;
  }
  else if(n == 40)
  {
    ans[2] = 3 * 5;
  }
  else if(n == 44)
  {
    ans[2] = 3 * 5;
  }
  ans[3] = n - ans[0] - ans[1] - ans[2];
  return ans;
}
template<class Ti, class To>
void func(Ti &i, To &o, ifstream &c)
{
  int t  = 0;
  i >> t;
  while(t--)
  {
    int n = 0;
    i.ignore(3, '\n');
    i >> n;
    vector<int> var = solve(n);
    if(var[4] == 1)
    {
      o << "No\n";
      continue;
    }
    o << "Yes\n";
    o << var[0] << " " << var[1]  << " " << var[2] << " " << var[3] << "\n";
  }
}
int main()
{
  ifstream checkFile, inFile("/Users/dreadarceus/github/Codeforces/Contests/Division 2/Round #660/A/input.txt");
  ofstream outFile;
  if(inFile.is_open())
  {
    checkFile.open("/Users/dreadarceus/github/Codeforces/Contests/Division 2/Round #660/A/correctOutput.txt");
    outFile.open("/Users/dreadarceus/github/Codeforces/Contests/Division 2/Round #660/A/output.txt");
    func(inFile, outFile, checkFile);
  }
  else
  {
    func(cin, cout, checkFile);
  }
}
