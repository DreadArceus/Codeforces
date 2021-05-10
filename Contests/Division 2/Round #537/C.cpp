#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t mod = 1e9 + 7;

struct segTreeItem
{
    int element;
};

vector<int> prefix;
int a = 0, b = 0;
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
        int res = a, num = prefix[r - 1] - (l != 0 ? prefix[l - 1] : 0);
        if (num != 0)
            res = b * num * (r - l);
        nodes[index].element = min(nodes[index].element, res);
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
    void pointUpdate(int x, int val)
    {
        pointUpdate(x, {val}, 1, 0, size);
    }
    segTreeItem query(int x, int y)
    {
        return query(x, y, 1, 0, size);
    }

private:
    vector<segTreeItem> nodes;
    segTreeItem null = {a};
    int size;
    segTreeItem merge(segTreeItem a, segTreeItem b)
    {
        segTreeItem result;
        result.element = a.element + b.element;
        return result;
    }
};

void solveCase()
{
    int n = 0, k = 0;
    cin >> n >> k >> a >> b;
    n = 1 << n;
    vector<int> v(n, 0);
    segTree st(n);
    for (int i = 0; i < k; i++)
    {
        int x = 0;
        cin >> x;
        x--;
        v[x] = 1;
    }
    prefix.assign(n, 0);
    prefix[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            continue;
        st.pointUpdate(i, b);
    }
    cout << st.query(0, n).element;
}

int32_t main()
{
    solveCase();
}