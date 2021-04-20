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
    map<int, int> mp;
};

class segTree
{
public:
    segTree(int n)
    {
        this->nodes.resize(4 * n + 5, this->null);
        this->size = n;
    }
    void pointUpdate(int x, int val, int index, int l, int r)
    {
        if (x < l || x >= r)
            return;
        if (l == x && r == x + 1)
        {
            nodes[index].mp[val]++;
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
    void pointUpdate(int x, int val)
    {
        pointUpdate(x, val, 1, 0, size);
    }
    segTreeItem query(int x, int y)
    {
        return query(x, y, 1, 0, size);
    }

private:
    vector<segTreeItem> nodes;
    segTreeItem null = {map<int, int>()};
    int size;
    segTreeItem merge(segTreeItem a, segTreeItem b)
    {
        segTreeItem result;
        result.mp = a.mp;
        auto it = b.mp.begin();
        while (it != b.mp.end())
        {
            result.mp[it->first] += it->second;
            it++;
        }
        return result;
    }
};

void solveCase()
{
    int n = 0, q = 0;
    cin >> n >> q;
    segTree st(n);
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        cin >> a;
        st.pointUpdate(i, a);
    }
    while (q--)
    {
        int l = 0, r = 0;
        cin >> l >> r;
        int maxSize = r - l + 1, maxAllowed = (maxSize + 1) / 2;
        int count = 1;
        map<int, int> mp = st.query(l - 1, r).mp;
        auto maxEle = max_element(mp.begin(), mp.end());
        while(maxAllowed < maxEle->second)
        {
            count++;
        }
        cout << count << "\n";
    }
    cout << "\n";
}

int32_t main()
{
    solveCase();
}