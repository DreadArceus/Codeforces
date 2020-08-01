#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;
string solve(int n)
{
  string s = "8";
  int i = 1, cnt = n;
  while(cnt > 4)
  {
    s.push_back('8');
    cnt -= 4;
    i++;
    n--;
  }
  while(n > 1)
  {
    s.insert(0, "9");
    n--;
  }
  return s;
}
template<class Ti, class To>
void func(Ti &in, To &o, ifstream &c)
{
  int t  = 0;
  in >> t;
  while(t--)
  {
    int n = 0;
    in.ignore(3, '\n');
    in >> n;
    string var = solve(n);
    if(c.is_open())
    {
      string ans = "";
      c >> ans;
      c.ignore(3, '\n');
      cout << "Testing.. ";
      if(var != ans)
      {
        cout << "Wrong Answer\n";
        //o << "x ";
      }
      else
      {
        cout << "Passed\n";
      }
    }
    o << var << "\n";
  }
}
int main()
{
  ifstream checkFile, inFile("/Users/dreadarceus/github/Codeforces/Contests/Division 2/Round #660/B/input.txt");
  ofstream outFile;
  if(inFile.is_open())
  {
    checkFile.open("/Users/dreadarceus/github/Codeforces/Contests/Division 2/Round #660/B/correctOutput.txt");
    outFile.open("/Users/dreadarceus/github/Codeforces/Contests/Division 2/Round #660/B/output.txt");
    func(inFile, outFile, checkFile);
  }
  else
  {
    func(cin, cout, checkFile);
  }
}
