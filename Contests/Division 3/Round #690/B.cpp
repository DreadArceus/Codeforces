#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        bool ans =
        ((s[0] == '2' && s.substr(n-3,3) == "020")
        || (s[0] == '2' && s[1] == '0' && s[n-2] == '2' && s[n-1] == '0')
        || (s.substr(0,3) == "202" && s[n-1] == '0')
        || (s.substr(0,4) == "2020")
        || (s.substr(n-4,4) == "2020"));
        cout << ((ans)?"YES":"NO") << "\n";
    }
}