#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool solve(vector<string> a, vector<string> b)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (a[i][j] != b[i][j])
                cnt++;
        if (cnt > (n - 1) / 2)
            for (int j = 0; j < n; j++)
                a[i][j] = ((a[i][j] == '1') ? '0' : '1');
        for (int j = 0; j < n; j++)
            if (a[i][j] != b[i][j])
                for (int x = 0; x < n; x++)
                    a[x][j] = ((a[x][j] == '1') ? '0' : '1');
    }
    bool possible = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != b[i][j])
                possible = false;
        }
    }
    return possible;
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        vector<string> a(n);
        vector<string> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        cout << (solve(a, b) ? "YES" : "NO") << "\n";
    }
}