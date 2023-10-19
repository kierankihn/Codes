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
    const int MAXLOGN = 20 + 5;
    int n, m;
    int a[MAXN];
    int v[MAXN][MAXLOGN];
    void build()
    {
        for (int i = 1; i <= n; i++)
        {
            v[i][0] = a[i];
        }
        for (int k = 1; k <= std::__lg(n); k++)
        {
            for (int i = 1; i + (1 << k) - 1 <= n; i++)
            {
                v[i][k] = std::max(v[i][k - 1], v[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    int query(int l, int r)
    {
        int k = std::__lg(r - l + 1);
        return std::max(v[l][k], v[r - (1 << k) + 1][k]);
    }
    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        build();
        for (int i = 1; i <= m; i++)
        {
            int l, r;
            read(l, r);
            write(query(l, r));
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}