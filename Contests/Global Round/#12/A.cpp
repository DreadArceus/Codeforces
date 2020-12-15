#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        string s;
        cin >> n >> s;
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'b')
            {
                s[i] = s[j];
                s[j] = 'b';
                j++;
            }
        }
        cout << s << "\n";
    }
}