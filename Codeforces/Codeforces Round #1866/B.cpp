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
    const int MAXV = 2e6 + 5;
    const int MOD = 998244353;
    using input::read;
    using output::write;
    LL ans = 1;
    int n, m;
    int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
    int ton[MAXV][2];
    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            read(b[i]);
        }
        read(m);
        for (int i = 1; i <= m; i++)
        {
            read(c[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            read(d[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            ton[a[i]][0] = b[i];
        }
        for (int i = 1; i <= m; i++)
        {
            ton[c[i]][1] = d[i];
        }
        for (int i = 1; i <= 2e6; i++)
        {
            if (ton[i][0] < ton[i][1])
            {
                write(0);
                return 0;
            }
            if (ton[i][0] > ton[i][1])
            {
                ans = ans * 2;
                ans = ans % MOD;
            }
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