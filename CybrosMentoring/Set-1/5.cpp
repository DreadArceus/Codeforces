#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    multiset<int> ms;
    for(int i = 0; i < s.length(); i+=2)
        ms.insert(s[i] - '0');
    int i = 0;
    for(auto begin = ms.begin(); begin != ms.end(); begin++)
        cout << *begin << ((i++ == ms.size() - 1) ? "" : "+");
}