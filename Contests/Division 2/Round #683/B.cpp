#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, m = 0;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        int maxSum = 0, minCell = INT32_MAX;
        bool oddNegatives = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                maxSum += abs(grid[i][j]);
                minCell = min(abs(grid[i][j]), minCell);
                if(grid[i][j] < 0)
                {
                    oddNegatives = !oddNegatives;
                }
            }
        }
        cout << maxSum - 2 * oddNegatives * minCell << "\n";
    }
}