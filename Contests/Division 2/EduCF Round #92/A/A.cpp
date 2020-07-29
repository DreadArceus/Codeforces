#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> solve(int l, int r)
{
  vector<int> x(2);
  if(l * 2 <= r)
  {
    x[0] = l;
    x[1] = x[0]*2;
  }
  else
  {
    x[0] = -1;
    x[1] = -1;
  }
  return x;
}
template<class Ti, class To>
void func(Ti &i, To &o, ifstream &c)
{
  int t  = 0;
  i >> t;
  while(t--)
  {
    int l = 0, r = 0;
    i.ignore(3, '\n');
    i >> l >> r;
    vector<int> var = solve(l, r);
    if(c.is_open())
    {
      for(int i = 0; i < var.size(); i++)
      {
        int ans = 0;
        c >> ans;
        cout << "Testing.. ";
        if(var[i] != ans)
        {
          cout << "Wrong Answer\n";
          o << "x ";
        }
        else
        {
          cout << "Passed\n";
        }
      }
      c.ignore(3, '\n');
    }
    o << var[0] << " " << var[1] << "\n";
  }
}
int main()
{
  ifstream checkFile, inFile("/Usrs/dreadarceus/github/Codeforces/Contests/Division 2/EduCF Round #92/A/input.txt");
  ofstream outFile;
  if(inFile.is_open())
  {
    checkFile.open("/Users/dreadarceus/github/Codeforces/Contests/Division 2/EduCF Round #92/A/correctOutput.txt");
    outFile.open("/Users/dreadarceus/github/Codeforces/Contests/Division 2/EduCF Round #92/A/output.txt");
    func(inFile, outFile, checkFile);
  }
  else
  {
    func(cin, cout, checkFile);
  }
}
