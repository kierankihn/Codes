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
    int n, m;
    int val[MAXN];
    int tag[MAXN << 2];
    void pushdown(int o, int l, int r)
    {
        if (l == r)
        {
            if (tag[o])
            {
                val[l] ^= 1;
            }
        }
        else
        {
            tag[o << 1] ^= tag[o], tag[o << 1 | 1] ^= tag[o];
        }
        tag[o] = 0;
    }
    void update(int o, int l, int r, int ql, int qr)
    {
        pushdown(o, l, r);
        if (ql <= l && r <= qr)
        {
            tag[o] ^= 1;
            return;
        }
        int mid = (l + r) >> 1;
        if (mid >= ql)
        {
            update(o << 1, l, mid, ql, qr);
        }
        if (mid < qr)
        {
            update(o << 1 | 1, mid + 1, r, ql, qr);
        }
    }
    int query(int o, int l, int r, int x)
    {
        pushdown(o, l, r);
        if (l == r)
        {
            return val[l];
        }
        int mid = (l + r) >> 1, res;
        if (x <= mid)
        {
            res = query(o << 1, l, mid, x);
        }
        if (x > mid)
        {
            res = query(o << 1 | 1, mid + 1, r, x);
        }
        return res;
    }
    int main()
    {
        read(n, m);
        for (int i = 1; i <= m; i++)
        {
            int op;
            read(op);
            if (op == 1)
            {
                int l, r;
                read(l, r);
                update(1, 1, n, l, r);
            }
            if (op == 2)
            {
                int x;
                read(x);
                write(query(1, 1, n, x));
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