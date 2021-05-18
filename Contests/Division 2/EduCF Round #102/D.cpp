// time-limit: 2000
// problem-url: https://codeforces.com/contest/1473/problem/D
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
// #define int long long
#define pii pair<int, int>
int32_t mod = 1e9 + 7;

struct segTreeItem
{
    int sum;
    int posPref;
    int negPref;
};

class segTree
{
public:
    segTree(int n)
    {
        this->nodes.resize(4 * n + 5, this->null);
        this->size = n;
    }
    void pointUpdate(int x, segTreeItem val, int index, int l, int r)
    {
        if (x < l || x >= r)
            return;
        if (l == x && r == x + 1)
        {
            nodes[index] = val;
            return;
        }
        pointUpdate(x, val, 2 * index, l, (r + l) / 2);
        pointUpdate(x, val, 2 * index + 1, (r + l) / 2, r);
        nodes[index] = merge(nodes[2 * index], nodes[2 * index + 1]);
    }
    segTreeItem query(int x, int y, int index, int l, int r)
    {
        if (y <= l || x >= r)
            return this->null;
        if (l >= x && r <= y)
            return nodes[index];
        return merge(query(x, y, 2 * index, l, (r + l) / 2),
                     query(x, y, 2 * index + 1, (r + l) / 2, r));
    }
    void pointUpdate(int x, segTreeItem val)
    {
        pointUpdate(x, val, 1, 0, size);
    }
    segTreeItem query(int x, int y)
    {
        return query(x, y, 1, 0, size);
    }

private:
    vector<segTreeItem> nodes;
    segTreeItem null = {0, 0, 0};
    int size;
    segTreeItem merge(segTreeItem a, segTreeItem b)
    {
        segTreeItem result;
        result.sum = a.sum + b.sum;

        result.posPref = max(a.posPref, a.sum + b.posPref);

        result.negPref = min(a.negPref, a.sum + b.negPref);

        return result;
    }
};

void solveCase()
{
    int n = 0, m = 0;
    string ins;
    cin >> n >> m >> ins;
    segTree st(n);
    for (int i = 0; i < n; i++)
    {
        if (ins[i] == '+')
            st.pointUpdate(i, {1, 1, 0});
        else
            st.pointUpdate(i, {-1, 0, -1});
    }
    while (m--)
    {
        int l = 0, r = 0;
        cin >> l >> r;
        l--;
        r--;
        auto res1 = st.query(0, l), res2 = st.query(r + 1, n);
        int ans = 1;
        ans += max(res1.posPref, res1.sum + res2.posPref);
        ans -= min(res1.negPref, res1.sum + res2.negPref);
        cout << ans << "\n";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}