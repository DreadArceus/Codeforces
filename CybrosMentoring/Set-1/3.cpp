#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    string s;
    cin >> s;
    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    for (char c : s)
    {
        if (!vowels.count(c))
        {
            cout << "." << char(tolower(c));
        }
    }
}