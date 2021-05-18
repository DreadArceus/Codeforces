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
    segTreeItem null = {0};
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
    int n = 0, q = 0;
    string s;
    cin >> n >> s >> q;
    segTree st(n);
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            st.pointUpdate(i, 1);
    }
    while (q--)
    {
        int type = 0;
        cin >> type;
        if (type == 1)
        {
            int l = 0, r = 0;
            cin >> l >> r;
            cout << st.query(l - 1, r).element << endl;
        }
        else
        {
            int i = 0;
            char c;
            cin >> i >> c;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                st.pointUpdate(i - 1, 1);
            else
                st.pointUpdate(i - 1, 0);
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solveCase();
}