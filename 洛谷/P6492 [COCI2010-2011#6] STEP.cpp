#include <bits/stdc++.h>
namespace input
{
    template <typename T>
    void read(T &x)
    {
        T res = 0, s = 1;
        char ch;
        while ((ch = getchar()) < '0' || ch > '9')
            if (ch == '-')
                s = -1;
        while (ch >= '0' && ch <= '9')
            res = res * 10 + ch - '0', ch = getchar();
        x = res * s;
    }
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        read(first);
        read(rest...);
    }
}
namespace output
{
    void write()
    {
        putchar('\n');
    }
    void write(char ch)
    {
        putchar(ch);
    }
    template <typename T>
    void write(char delimiter, T x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            write(delimiter, x / 10);
        putchar((x % 10) + '0');
    }
    template <typename First, typename... Rest>
    void write(char delimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
    }
    template <typename First, typename... Rest>
    void write(char delimiter, char linedelimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
        putchar(linedelimiter);
    }
    template <typename... T>
    void write(T... t)
    {
        write(' ', '\n', t...);
    }
}
namespace solution
{
    typedef long long LL;
    using input::read;
    using output::write;
    const int MAXN = 2e5 + 5;
    struct Node
    {
        int maxl, maxr;
        int max;
        int left, right;
    };
    int n, m;
    int tmpl, tmpr;
    Node node[MAXN << 2];
    Node operator+(const Node a, const Node b)
    {
        Node c;
        int l = tmpl, r = tmpr;
        int mid = (l + r) >> 1;
        c.left = a.left;
        c.right = b.right;
        c.maxl = a.maxl;
        c.maxr = b.maxr;
        if (a.maxl == mid - l + 1 && a.right != b.left)
        {
            c.maxl = a.maxl + b.maxl;
        }
        if (b.maxr == r - (mid + 1) + 1 && a.right != b.left)
        {
            c.maxr = a.maxr + b.maxr;
        }
        c.max = std::max(a.max, b.max);
        if (a.right != b.left)
        {
            c.max = std::max(c.max, a.maxr + b.maxl);
        }
        return c;
    }
    void pushup(int o, int l, int r)
    {
        tmpl = l, tmpr = r;
        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void build(int o, int l, int r)
    {
        if (l == r)
        {
            node[o].left = node[o].right = 0, node[o].max = node[o].maxl = node[o].maxr = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        pushup(o, l, r);
    }
    void update(int o, int l, int r, int x)
    {
        if (l == r)
        {
            node[o].left = node[o].left ^ 1;
            node[o].right = node[o].right ^ 1;
            return;
        }
        int mid = (l + r) >> 1;
        if (mid >= x)
        {
            update(o << 1, l, mid, x);
        }
        if (mid < x)
        {
            update(o << 1 | 1, mid + 1, r, x);
        }
        pushup(o, l, r);
    }
    Node query(int o, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return node[o];
        }
        int mid = (l + r) >> 1;
        Node res;
        if (mid >= ql && mid < qr)
        {
            Node a = query(o << 1, l, mid, ql, qr), b = query(o << 1 | 1, mid + 1, r, ql, qr);
            tmpl = l, tmpr = r;
            res = a + b;
        }
        else
        {
            if (mid >= ql)
            {
                res = query(o << 1, l, mid, ql, qr);
            }
            if (mid < qr)
            {
                res = query(o << 1 | 1, mid + 1, r, ql, qr);
            }
        }
        return res;
    }
    int main()
    {
        read(n, m);
        build(1, 1, n);
        for (int i = 1; i <= m; i++)
        {
            int x;
            read(x);
            update(1, 1, n, x);
            write(query(1, 1, n, 1, n).max);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}