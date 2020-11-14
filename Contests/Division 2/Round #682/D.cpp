//Based on XOR basics
//Also the XOR of the whole array never changes, this is used to check if
//  in the case of an even n, XOR(a) = 0
//  which implies that at the end of the odd n process the extra value would already be the same as the rest.
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> solve(int a[], int n)
{
    vector<vector<int>> moves;
    if(n % 2 != 0)
    {
        for(int i = 1; i < n - 1; i += 2)
        {
            vector<int> v = {0, i, i + 1};
            moves.push_back(v);
        }
        for(int i = 1; i < n - 1; i += 2)
        {
            vector<int> v = {0, i, i + 1};
            moves.push_back(v);
        }
    }
    else
    {
        int XOR = 0;
        for(int i = 0; i < n; i++)
        {
            XOR = XOR ^ a[i];
        }
        if(XOR == 0)
        {
            for(int i = 2; i < n - 1; i += 2)
            {
                vector<int> v = {1, i, i + 1};
                moves.push_back(v);
            }
            for(int i = 2; i < n - 1; i += 2)
            {
                vector<int> v = {1, i, i + 1};
                moves.push_back(v);
            }
        }
        else
        {
            return {{-1}};
        }
    }
    return moves;
}

int main()
{
    int n = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> moves = solve(a, n);
    if(moves[0][0] != -1)
    {
        cout << "YES\n" << moves.size() << "\n";
        for(auto x : moves)
        {
            for(auto y : x)
            {
                cout << y + 1 << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "NO\n";
    }
}