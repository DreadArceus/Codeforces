#include <iostream>
#include <set>
using namespace std;
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n = 0;
    cin >> n;
    set<int> st;
    for(int i = 0; i < n; i++)
    {
      int loc = 0;
      cin >> loc;
      st.insert(loc);
    }
    int ans = ((st.size() == 1) ? n : 1);
    cout << ans << "\n";
  }
}
