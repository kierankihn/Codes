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
    int startsum[MAXN << 2], endsum[MAXN << 2];
    int lowbit(int x)
    {
        return x & (-x);
    }
    void update(int *s, int x, int v)
    {
        while (x <= n)
        {
            s[x] += v;
            x += lowbit(x);
        }
    }
    int query(int *s, int x)
    {
        int res = 0;
        while (x > 0)
        {
            res += s[x];
            x -= lowbit(x);
        }
        return res;
    }
    int main()
    {
        read(n, m);
        for (int i = 1; i <= m; i++)
        {
            int op, l, r;
            read(op, l, r);
            if (op == 1)
            {
                update(startsum, l, 1);
                update(endsum, r, 1);
            }
            if (op == 2)
            {
                write(query(startsum, r) - query(endsum, l - 1));
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