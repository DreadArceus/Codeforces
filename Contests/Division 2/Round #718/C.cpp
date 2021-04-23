#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define int long long
#define pii pair<int, int>

/*
(5, 3, 4, 1, 2)-->
 5
 53
 534
 5341
 54422

(5, 1, 3, 2, 4)-->
 5
 51
 533
 5322
 54444

(3, 2, 1, 5, 4)-->
 3
 32
 321
 5555
 54444

(2, 1, 5, 4, 3)-->
 2
 21
 555
 5444
 54333

(4, 5, 2, 1, 3)-->
 4
 45
 452
 4521
 55333

(3, 4, 1, 2, 5)-->
3
34
341
4422
55555
*/

void solveCase()
{
    int n = 0;
    cin >> n;
    vector<int> p(n);
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        ans[i][i] = p[i];
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        int locI = i, locJ = i;
        while (true)
        {
            if (cnt == ans[i][i] - 1)
                break;
            if ((i != 0 || p[i - 1] > i) && ans[locI][locJ - 1] == 0)
                locJ--;
            else
                locI++;
            if (locI >= n || locJ < 0)
                break;
            if (ans[locI][locJ] != 0)
                continue;
            ans[locI][locJ] = ans[i][i];
            cnt++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}

int32_t main()
{
    solveCase();
}