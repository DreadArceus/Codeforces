#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int k = 0;
    cin >> s >> k;

    int canes = 0, flakes = 0, letters = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '*')
            flakes++;
        else if (s[i] == '?')
            canes++;
        else
            letters++;
    }

    if (k == letters)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '*' || s[i] == '?')
                continue;
            cout << s[i];
        }
    }
    else if (k > letters)
    {
        if (flakes == 0)
        {
            cout << "Impossible";
            return 0;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '?')
                continue;
            if (s[i] == '*')
                while (k-- > letters)
                    cout << s[i - 1];
            else
                cout << s[i];
        }
    }
    else
    {
        if (flakes + canes < letters - k)
        {
            cout << "Impossible";
            return 0;
        }
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i - 1] == '?' || s[i - 1] == '*')
                continue;
            if (s[i] == '?' || s[i] == '*')
            {
                if (letters-- > k)
                    continue;
            }
            cout << s[i - 1];
        }
        char lastChar = s[s.length() - 1];
        if(lastChar != '?' && lastChar != '*')
            cout << lastChar;
    }
}