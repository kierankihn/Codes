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
    const int MAXV = 1e5 + 5;
    using input::read;
    using output::write;
    int n, m;
    LL ans = 0;
    int node1[MAXV << 2], node2[MAXV << 2];
    void update(int *val, int o, int l, int r, int x, int v)
    {
        if (l == r)
        {
            val[o] += v;
            return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(val, o << 1, l, mid, x, v);
        }
        if (x > mid)
        {
            update(val, o << 1 | 1, mid + 1, r, x, v);
        }
        val[o] = val[o << 1] + val[o << 1 | 1];
    }
    int query(int *val, int o, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return val[o];
        }
        int mid = (l + r) >> 1, res = 0;
        if (mid >= ql)
        {
            res += query(val, o << 1, l, mid, ql, qr);
        }
        if (mid < qr)
        {
            res += query(val, o << 1 | 1, mid + 1, r, ql, qr);
        }
        return res;
    }
    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            int tmp;
            read(tmp);
            ans += query(node2, 1, 0, 1e5, 1, tmp - 1);
            update(node2, 1, 0, 1e5, tmp, query(node1, 1, 0, 1e5, 1, tmp - 1));
            update(node1, 1, 0, 1e5, tmp, 1);
        }
        write(ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}