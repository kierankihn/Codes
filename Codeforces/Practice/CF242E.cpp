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
    const int MAXN = 1e5 + 5;
    const int LOGX = 20;
    const int MAXLOGX = 30;
    struct Node
    {
        LL sum;
        LL tag;
        LL cnt[MAXLOGX];
    };
    int n, m;
    LL a[MAXN];
    Node node[MAXN << 2];
    void pushup(int o, int l, int r)
    {
        node[o].sum = node[o << 1].sum + node[o << 1 | 1].sum;
        for (int i = 1; i <= LOGX; i++)
        {
            node[o].cnt[i] = node[o << 1].cnt[i] + node[o << 1 | 1].cnt[i];
        }
    }
    void pushdown(int o, int l, int r)
    {
        int mid = (l + r) >> 1;
        for (int i = 1; i <= LOGX; i++)
        {
            if ((1 << (i - 1)) & node[o].tag)
            {
                // write(o, l, r, i, node[o].tag);
                node[o << 1].sum += (mid - l + 1 - node[o << 1].cnt[i] - node[o << 1].cnt[i]) * (1 << (i - 1));
                node[o << 1].cnt[i] = mid - l + 1 - node[o << 1].cnt[i];
            }
        }
        for (int i = 1; i <= LOGX; i++)
        {
            if ((1 << (i - 1)) & node[o].tag)
            {
                // write(o, l, r, i, node[o].tag);
                node[o << 1 | 1].sum += (r - (mid + 1) + 1 - node[o << 1 | 1].cnt[i] - node[o << 1 | 1].cnt[i]) * (1 << (i - 1));
                node[o << 1 | 1].cnt[i] = r - (mid + 1) + 1 - node[o << 1 | 1].cnt[i];
            }
        }
        node[o << 1].tag = node[o << 1].tag ^ node[o].tag;
        node[o << 1 | 1].tag = node[o << 1 | 1].tag ^ node[o].tag;
        node[o].tag = 0;
    }
    void build(int o, int l, int r)
    {
        if (l == r)
        {
            node[o].tag = 0;
            node[o].sum = a[l];
            for (int i = 1; i <= LOGX; i++)
            {
                if ((1 << (i - 1)) & a[l])
                {
                    node[o].cnt[i] = 1;
                }
            }
            return;
        }
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        node[o].tag = 0;
        pushup(o, l, r);
    }
    void update(int o, int l, int r, int ql, int qr, LL v)
    {
        if (ql <= l && r <= qr)
        {
            node[o].tag = node[o].tag ^ v;
            for (int i = 1; i <= LOGX; i++)
            {
                if ((1 << (i - 1)) & v)
                {
                    node[o].sum += (r - l + 1 - node[o].cnt[i] - node[o].cnt[i]) * (1 << (i - 1));
                    node[o].cnt[i] = r - l + 1 - node[o].cnt[i];
                }
            }
            return;
        }
        pushdown(o, l, r);
        int mid = (l + r) >> 1;
        if (mid >= ql)
        {
            update(o << 1, l, mid, ql, qr, v);
        }
        if (mid < qr)
        {
            update(o << 1 | 1, mid + 1, r, ql, qr, v);
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
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        read(m);
        build(1, 1, n);
        for (int i = 1; i <= m; i++)
        {
            int op;
            read(op);
            if (op == 1)
            {
                int l, r;
                read(l, r);
                write(query(1, 1, n, l, r));
            }
            if (op == 2)
            {
                int l, r, v;
                read(l, r, v);
                update(1, 1, n, l, r, v);
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