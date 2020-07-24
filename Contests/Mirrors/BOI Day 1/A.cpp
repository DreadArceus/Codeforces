//This one's hard to think about, can't even figure out how to get the N ≤ 64 case
//The logic is trying all 64 possible critical values starting from 1 by running queries
//First to return 1 is the answer. Can't manage to do this without going outside of N.
#include <iostream>
using namespace std;
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int N = 0;
    cin >> N;
    cout << "? " << 1 << endl;
    int fb = -1;
    cin >> fb;
    int P = 0, P_old  = 1;
    for(int i = 1; ; i++)
    {
      P = P_old + i;
      if(P > N)
      {
        P = P_old - i;
      }
      cout << "? " << P << endl;
      cin >> fb;
      if(fb == 1)
      {
        cout << "= " << i << endl;
        break;
      }
      P_old = P;
    }
  }
}
