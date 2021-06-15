#include <bits/stdc++.h>
using namespace std;

struct SegTreeItem
{
    int element;
};

class SegTree
{
  public:
    SegTree(int n)
    {
        this->nodes.resize(4 * n + 5, this->null);
        this->size = n;
    }
    void pointUpdate(int x, SegTreeItem val, int index, int l, int r)
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
    SegTreeItem query(int x, int y, int index, int l, int r)
    {
        if (y <= l || x >= r)
            return this->null;
        if (l >= x && r <= y)
            return nodes[index];
        return merge(query(x, y, 2 * index, l, (r + l) / 2), query(x, y, 2 * index + 1, (r + l) / 2, r));
    }
    void pointUpdate(int x, int val)
    {
        pointUpdate(x, {val}, 1, 0, size);
    }
    SegTreeItem query(int x, int y)
    {
        return query(x, y, 1, 0, size);
    }

  private:
    vector<SegTreeItem> nodes;
    SegTreeItem null = {0};
    int size;
    SegTreeItem merge(SegTreeItem a, SegTreeItem b)
    {
        SegTreeItem result;
        result.element = a.element + b.element;
        return result;
    }
};

void solveCase()
{
    auto isVowel = [](char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };

    int n = 0, q = 0;
    string s;
    cin >> n >> s >> q;

    SegTree st(n);
    for (int i = 0; i < n; i++)
        if (isVowel(s[i]))
            st.pointUpdate(i, 1);

    while (q--)
    {
        int type = 0;
        cin >> type;
        if (type == 1)
        {
            int l = 0, r = 0;
            cin >> l >> r;
            cout << st.query(l - 1, r).element << '\n';
        }
        else
        {
            int i = 0;
            char c;
            cin >> i >> c;
            st.pointUpdate(i - 1, isVowel(c));
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    solveCase();
}