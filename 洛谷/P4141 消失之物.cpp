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
    const int MAXN = 2000 + 5;
    using input::read;
    using output::write;
    int n, m;
    int v[MAXN];
    LL f[MAXN], g[MAXN];
    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(v[i]);
        }
        f[0] = g[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= v[i]; j--)
            {
                f[j] += f[j - v[i]];
                f[j] %= 10;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j >= v[i])
                {
                    g[j] = f[j] - g[j - v[i]];
                }
                else
                {
                    g[j] = f[j];
                }
                g[j] %= 10, g[j] += 10, g[j] %= 10;
                std::cout << g[j];
            }
            std::cout << std::endl;
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}