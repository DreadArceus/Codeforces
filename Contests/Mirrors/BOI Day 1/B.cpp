//How to actually solve it? dunno
//But this is the io shell.
#include <iostream>
#include <vector>
using namespace std;
int solve(vector<vector<int> > shelf, int S, int R, int G)
{
  
}
int main()
{
  int S = 0, R = 0, G = 0, N = 0;
  cin >> S >> R >> G >> N;
  vector<vector<int> > shelf;
  for(int i = 0; i < N; i++)
  {
    char op = '';
    cin >> op;
    if(op == 'A')
    {
      vector<int> mix(3);
      cin >> mix[0] >> mix[1] >> mix[2];
      shelf.push_back(mix);
      int ans = solve(mix, S, R, G);
      cout << ans << "\n";
    }
    else
    {
      int i = 0;
      cin >> i;
      shelf[i - 1][0] = -1;
      shelf[i - 1][1] = -1;
      shelf[i - 1][2] = -1;
      int ans  = solve(mix, S, R, G);
      cout << ans << "\n";
    }
  }
}
