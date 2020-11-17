#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, c0 = 0, c1 = 0, h = 0;
        cin >> n >> c0 >> c1 >> h;
        string s;
        cin >> s;
        int coins = 0;
        if(c0 > h + c1)
        {
            for(char c : s)
            {
                if(c == '0')
                {
                    coins += c1 + h;
                }
                else
                {
                    coins += c1;
                }
            }
        }
        else if(c1 > h + c0)
        {
            for(char c : s)
            {
                if(c == '0')
                {
                    coins += c0;
                }
                else
                {
                    coins += c0 + h;
                }
            }
        }
        else
        {
            for(char c : s)
            {
                if(c == '0')
                {
                    coins += c0;
                }
                else
                {
                    coins += c1;
                }
            }

        }
        cout << coins << "\n";
    }
}