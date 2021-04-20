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

struct segTreeItem
{
    int element;
    int index;
};

class lazySegTree
{
public:
    lazySegTree(int n)
    {
        this->nodes.resize(4 * n + 5, this->null);
        this->lazy.resize(4 * n + 5, {0});
        this->pendingLazy.resize(4 * n + 5, false);
        this->size = n;
    }
    void pointUpdate(int x, segTreeItem val, int index, int l, int r)
    {
        if (pendingLazy[index])
            propagateLazy(index, l, r);
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
    void rangeUpdate(int x, int y, segTreeItem val, int index, int l, int r)
    {
        if (pendingLazy[index])
            propagateLazy(index, l, r);
        if (y <= l || x >= r)
            return;
        if (l >= x && r <= y)
        {
            pendingLazy[index] = true;
            lazy[index] = val;
            propagateLazy(index, l, r);
            return;
        }
        rangeUpdate(x, y, val, 2 * index, l, (r + l) / 2);
        rangeUpdate(x, y, val, 2 * index + 1, (r + l) / 2, r);
        nodes[index] = merge(nodes[2 * index], nodes[2 * index + 1]);
    }
    segTreeItem query(int x, int y, int index, int l, int r)
    {
        if (pendingLazy[index])
            propagateLazy(index, l, r);
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
        pointUpdate(x, {val, x}, 1, 0, size);
    }
    void rangeUpdate(int x, int y, segTreeItem val)
    {
        rangeUpdate(x, y, val, 1, 0, size);
    }
    void rangeUpdate(int x, int y, int val)
    {
        rangeUpdate(x, y, {val}, 1, 0, size);
    }
    segTreeItem query(int x, int y)
    {
        return query(x, y, 1, 0, size);
    }

private:
    vector<segTreeItem> nodes, lazy;
    vector<bool> pendingLazy;
    segTreeItem null = {INT64_MIN};
    int size;
    void propagateLazy(int index, int l, int r)
    {
        if (l != r - 1)
        {
            pendingLazy[2 * index] = true;
            pendingLazy[2 * index + 1] = true;
            lazy[2 * index].element += lazy[index].element;
            lazy[2 * index + 1].element += lazy[index].element;
        }
        nodes[index].element += lazy[index].element;
        lazy[index].element = 0;
        pendingLazy[index] = false;
    }
    segTreeItem merge(segTreeItem a, segTreeItem b)
    {
        segTreeItem result;
        if (a.element > b.element)
            result = a;
        if (a.element <= b.element)
            result = b;
        return result;
    }
};

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m;
    lazySegTree st(n);
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        cin >> a;
        st.pointUpdate(i, a);
    }
    vector<pii> segments;
    for (int i = 0; i < m; i++)
    {
        int l = 0, r = 0;
        cin >> l >> r;
        segments.push_back(make_pair(l, r));
    }
    vector<int> ans;
    int maxDif = INT32_MIN, minEIndex = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int l = segments[j].first, r = segments[j].second;
            if (l > i || r < i)
                continue;
            st.rangeUpdate(l - 1, r, -1);
        }
        int current = st.query(0, n).element - st.query(i - 1, i).element;
        if (maxDif < current)
        {
            maxDif = current;
            minEIndex = i;
        }
        for (int j = 0; j < m; j++)
        {
            int l = segments[j].first, r = segments[j].second;
            if (l > i || r < i)
                continue;
            st.rangeUpdate(l - 1, r, 1);
        }
    }
    for (int j = 0; j < m; j++)
    {
        int l = segments[j].first, r = segments[j].second;
        if (l > minEIndex || r < minEIndex)
            continue;
        ans.push_back(j + 1);
    }

    cout << maxDif << "\n";
    cout << ans.size() << "\n";
    for (auto i : ans)
    {
        cout << i << " ";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solveCase();
}