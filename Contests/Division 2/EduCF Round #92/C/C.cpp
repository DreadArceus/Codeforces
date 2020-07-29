//Loads of cases, gave up for now -29-7-20
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
int solve(string s)
{
  unordered_set<char> uq(s.begin(), s.end());
  if(uq.size() == 2)
  {
    
  }
  vector<vector<int> > v(uq.size());
  for(char c : uq)
  {
    vector<int> local(2);
    local[0] = c;
    local[1] = 0;
    for(char d : s)
    {
      if(c == d)
      {
        local[1]++;
      }
    }
    v.push_back(local);
  }
  return 0;
}
template<class Ti, class To>
void func(Ti &in, To &o, ifstream &c)
{
  int t  = 0;
  in >> t;
  while(t--)
  {
    string s = "";
    in.ignore(3, '\n');
    in >> s;
    int var = solve(s);
    if(c.is_open())
    {
      int ans = 0;
      c >> ans;
      c.ignore(3, '\n');
      cout << "Testing.. ";
      if(var != ans)
      {
        cout << "Wrong Answer\n";
        o << "x ";
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
  ifstream checkFile, inFile("/Users/dreadarceus/github/Codeforces/Contests/Division 2/EduCF Round #92/C/input.txt");
  ofstream outFile;
  if(inFile.is_open())
  {
    checkFile.open("/Users/dreadarceus/github/Codeforces/Contests/Division 2/EduCF Round #92/C/correctOutput.txt");
    outFile.open("/Users/dreadarceus/github/Codeforces/Contests/Division 2/EduCF Round #92/C/output.txt");
    func(inFile, outFile, checkFile);
  }
  else
  {
    func(cin, cout, checkFile);
  }
}
