//Incomplete Logic, same thing as path finding, i think.
#include <iostream>
#include <fstream>
using namespace std;
int solve(int a[], int n, int k, int z)
{
  int x = a[0], i = 0;
  bool lastmoveLeft = false;
  while(k--)
  {
    if(i > 0 && z > 0 && !lastmoveLeft &&
      (i == n - 1 || a[i-1] > a[i+1]))
    {
      z--;
      i--;
      x += a[i];
      lastmoveLeft = true;
    }
    else if(i < n - 1)
    {
      lastmoveLeft = false;
      i++;
      x += a[i];
    }
  }
  return x;
}
template<class Ti, class To>
void func(Ti &in, To &o, ifstream &c)
{
  int t  = 0;
  in >> t;
  while(t--)
  {
    int n = 0, k = 0, z = 0;
    in.ignore(3, '\n');
    in >> n >> k >> z;
    int a[n];
    for(int i = 0; i < n; i++)
    {
      in >> a[i];
    }
    int var = solve(a, n, k, z);
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
  ifstream checkFile, inFile("/Users/dreadarceus/github/Codeforces/Contests/Division 2/EduCF Round #92/B/input.txt");
  ofstream outFile;
  if(inFile.is_open())
  {
    checkFile.open("/Users/dreadarceus/github/Codeforces/Contests/Division 2/EduCF Round #92/B/correctOutput.txt");
    outFile.open("/Users/dreadarceus/github/Codeforces/Contests/Division 2/EduCF Round #92/B/output.txt");
    func(inFile, outFile, checkFile);
  }
  else
  {
    func(cin, cout, checkFile);
  }
}
