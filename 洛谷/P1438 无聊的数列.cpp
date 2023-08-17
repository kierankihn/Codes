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
    const int MAXN = 1e5 + 5;
    using input::read;
    using output::write;
    struct Node
    {
        LL sum;
        LL tagk, tagd;
    };
    int n, m;
    LL a[MAXN];
    Node node[MAXN << 2];
    void pushup(int o, int l, int r)
    {
        node[o].sum = node[o << 1].sum + node[o << 1 | 1].sum;
    }
    void pushdown(int o, int l, int r)
    {
        int mid = (l + r) >> 1;
        int lenl = (mid - l + 1), lenr = (r - mid);
        LL frontl = node[o].tagk, frontr = node[o].tagk + lenl * node[o].tagd;
        LL endl = frontl + (lenl - 1) * node[o].tagd, endr = frontr + (lenr - 1) * node[o].tagd;
        node[o << 1].sum += (frontl + endl) * lenl / 2, node[o << 1 | 1].sum += (frontr + endr) * lenr / 2;
        node[o << 1].tagk += frontl, node[o << 1 | 1].tagk += frontr;
        node[o << 1].tagd += node[o].tagd, node[o << 1 | 1].tagd += node[o].tagd;
        node[o].tagk = node[o].tagd = 0;
    }
    void build(int o, int l, int r)
    {
        if (l == r)
        {
            node[o].sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        pushup(o, l, r);
    }
    void update(int o, int l, int r, int ql, int qr, int k, int d)
    {
        if (ql <= l && r <= qr)
        {
            int len = r - l + 1;
            LL front = k;
            LL end = k + (len - 1) * d;
            node[o].sum += (front + end) * len / 2;
            node[o].tagk += k, node[o].tagd += d;
            return;
        }
        pushdown(o, l, r);
        int mid = (l + r) >> 1;
        int newk = (mid - l + 1) * d + k;
        if (mid >= ql)
        {
            update(o << 1, l, mid, ql, qr, k, d);
        }
        if (mid < qr)
        {
            update(o << 1 | 1, mid + 1, r, ql, qr, newk, d);
        }
        pushup(o, l, r);
    }
    LL query(int o, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return node[o].sum;
        }
        pushdown(o, l, r);
        int mid = (l + r) >> 1;
        LL res = 0;
        if (mid >= ql)
        {
            res += query(o << 1, l, mid, ql, qr);
        }
        if (mid < qr)
        {
            res += query(o << 1 | 1, mid + 1, r, ql, qr);
        }
        return res;
    }
    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        build(1, 1, n);
        for (int i = 1; i <= m; i++)
        {
            int op;
            read(op);
            if (op == 1)
            {
                int l, r, k, d;
                read(l, r, k, d);
                update(1, 1, n, l, r, (1 - l) * d + k, d);
            }
            if (op == 2)
            {
                int x;
                read(x);
                write(query(1, 1, n, x, x));
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}