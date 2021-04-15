#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
#define pii pair<int, int>

struct block
{
    int c1, c2, val;
};

set<int> cMatcher[4];

pair<int, set<int>> recurse(vector<block> blocks, set<int> visited, int c)
{
    int maxVal = 0;
    set<int> newVisited(visited);
    if (c == -1)
        for (int i = 0; i < blocks.size(); i++)
        {
            block current = blocks[i];
            int locVal = current.val;
            set<int> locVisited(visited);
            locVisited.insert(i);
            pair<int, set<int>> opt1 = recurse(blocks, locVisited, current.c1);
            pair<int, set<int>> opt2 = recurse(blocks, locVisited, current.c2);
            pair<int, set<int>> res1, res2;
            res1 = recurse(blocks, opt1.second, current.c2);
            res2 = recurse(blocks, opt2.second, current.c1);
            locVal += max(res1.first + opt1.first, res2.first + opt2.first);
            if (locVal > maxVal)
            {
                maxVal = locVal;
                newVisited = locVisited;
            }
        }
    else
        for (auto i : cMatcher[c - 1])
        {
            block current = blocks[i];
            int locVal = current.val;
            if (visited.find(i) != visited.end())
                continue;
            set<int> locVisited(visited);
            locVisited.insert(i);
            pair<int, set<int>> res;
            if (current.c1 == c)
                res = recurse(blocks, locVisited, current.c2);
            else
                res = recurse(blocks, locVisited, current.c1);
            locVal += res.first;
            locVisited = res.second;
            if (locVal > maxVal)
            {
                maxVal = locVal;
                newVisited = locVisited;
            }
        }
    return make_pair(maxVal, newVisited);
}

void solveCase()
{
    int n = 0;
    cin >> n;
    vector<block> blocks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> blocks[i].c1 >> blocks[i].val >> blocks[i].c2;
        cMatcher[blocks[i].c1 - 1].insert(i);
        cMatcher[blocks[i].c2 - 1].insert(i);
    }
    int maxValue = recurse(blocks, set<int>(), -1).first;
    cout << maxValue;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solveCase();
}