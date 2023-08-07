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
    const int MAXN = 2e5 + 5;
    int n, m;
    int a[MAXN];
    int val[MAXN << 2];
    void build(int o, int l, int r)
    {
        if (l == r)
        {
            val[o] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        val[o] = std::max(val[o << 1], val[o << 1 | 1]);
    }
    void update(int o, int l, int r, int x, int v)
    {
        if (l == r)
        {
            val[o] = std::max(val[o], v);
            return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(o << 1, l, mid, x, v);
        }
        if (x > mid)
        {
            update(o << 1 | 1, mid + 1, r, x, v);
        }
        val[o] = std::max(val[o << 1], val[o << 1 | 1]);
    }
    int query(int o, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return val[o];
        }
        int mid = (l + r) >> 1;
        int res = 0;
        if (mid >= ql)
        {
            res = std::max(res, query(o << 1, l, mid, ql, qr));
        }
        if (mid < qr)
        {
            res = std::max(res, query(o << 1 | 1, mid + 1, r, ql, qr));
        }
        return res;
    }
    int main()
    {
        using input::read;
        using output::write;
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        build(1, 1, n);
        for (int i = 1; i <= m; i++)
        {
            char op;
            std::cin >> op;
            if (op == 'Q')
            {
                int l, r;
                read(l, r);
                write(query(1, 1, n, l, r));
            }
            if (op == 'U')
            {
                int x, v;
                read(x, v);
                update(1, 1, n, x, v);
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