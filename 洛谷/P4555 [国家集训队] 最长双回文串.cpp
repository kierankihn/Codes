#include <bits/stdc++.h>
namespace solution
{
    typedef char chr;
    typedef long long i64;
    const int MAXN = 2e5 + 5;
    struct Node
    {
        int v, tag;
    };
    int n;
    int ans = 0;
    int d[MAXN];
    chr s[MAXN];
    Node node[MAXN << 2];
    void read()
    {
        char ch;
        s[n = 1] = '#';
        while (isalpha(ch = getchar()))
        {
            s[++n] = ch, s[++n] = '#';
        }
    }
    void pushdown(int o)
    {
        node[o << 1].v = std::max(node[o << 1].v, node[o].tag), node[o << 1 | 1].v = std::max(node[o << 1 | 1].v, node[o].tag);
        node[o << 1].tag = std::max(node[o << 1].tag, node[o].tag), node[o << 1 | 1].tag = std::max(node[o << 1 | 1].tag, node[o].tag);
        node[o].tag = 0;
    }
    void update(int ql, int qr, int v, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            node[o].v = std::max(node[o].v, v), node[o].tag = std::max(node[o].tag, v);
            return;
        }
        pushdown(o);
        int mid = (l + r) >> 1;
        if (mid >= ql)
        {
            update(ql, qr, v, o << 1, l, mid);
        }
        if (mid < qr)
        {
            update(ql, qr, v, o << 1 | 1, mid + 1, r);
        }
    }
    int query(int ql, int qr, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            return node[o].v;
        }
        pushdown(o);
        int mid = (l + r) >> 1, res = 0;
        if (mid >= ql)
        {
            res = std::max(res, query(ql, qr, o << 1, l, mid));
        }
        if (mid < qr)
        {
            res = std::max(res, query(ql, qr, o << 1 | 1, mid + 1, r));
        }
        return res;
    }
    void manacher()
    {
        int l = 0, r = 0;
        for (int i = 1; i <= n; i++)
        {
            int len = 1;
            if (i < r)
            {
                len = std::min(d[l + r - i], r - i + 1);
            }
            while (1 <= i - len && i + len <= n && s[i - len] == s[i + len])
            {
                len++;
            }
            d[i] = len;
            if (i + len - 1 > r)
            {
                l = i - len + 1, r = i + len - 1;
            }
            update(i - len + 1, i, i);
        }
    }
    int main()
    {
        read();
        manacher();
        for (int i = 1; i <= n; i++)
        {
            if (d[i] != 1 && i + d[i] - 1 != n)
            {
                ans = std::max(ans, query(i + d[i], i + d[i]) - i);
            }
        }
        printf("%d\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}