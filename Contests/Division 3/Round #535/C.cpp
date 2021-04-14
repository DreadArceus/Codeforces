#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long

void solveCase()
{
    int n = 0;
    string s;
    cin >> n >> s;

    vector<string> perms;
    perms.push_back("BGR");
    for (int i = 1; i < 6; i++)
    {
        string next = perms[i - 1];
        next_permutation(next.begin(), next.end());
        perms.push_back(next);
    }

    vector<int> permScores(6, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 6; j++)
            permScores[j] += (perms[j][i % 3] != s[i]);


    int minScore = INT32_MAX;
    string minPerm;
    for (int i = 0; i < 6; i++)
    {
        if(permScores[i] < minScore)
        {
            minScore = permScores[i];
            minPerm = perms[i];
        }
    }
    
    cout << minScore << "\n";
    for (int i = 0; i < n; i++)
        cout << minPerm[i % 3];
}

int32_t main()
{
    solveCase();
}