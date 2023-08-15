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
    const int MAXN = 100 + 5;
    const int MAXC = 1e4 + 5;
    const int MAXV = 120 + 5;
    const int MAXT = 1e4 + 5;
    const int INF = 0x3f3f3f3f;
    using input::read;
    using output::write;
    int n, t;
    int sum;
    int ans = INF;
    int maxv2;
    int c[MAXN], v[MAXN];
    int f[MAXT + MAXV * MAXV];
    int g[MAXT + MAXV * MAXV];
    int main()
    {
        std::memset(f, 0x3f, sizeof(f)), std::memset(g, 0x3f, sizeof(g));
        f[0] = g[0] = 0;
        read(n, t);
        for (int i = 1; i <= n; i++)
        {
            read(v[i]);
            maxv2 = std::max(maxv2, v[i] * v[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            read(c[i]);
            sum += v[i] * c[i];
        }
        if (sum < t)
        {
            write(-1);
            return 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = v[i]; j <= maxv2; j++)
            {
                f[j] = std::min(f[j], f[j - v[i]] + 1);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= c[i]; j <<= 1)
            {
                for (int k = t + maxv2; k >= j * v[i]; k--)
                {
                    g[k] = std::min(g[k], g[k - j * v[i]] + j);
                }
                c[i] -= j;
            }
            if (c[i])
            {
                for (int k = t + maxv2; k >= v[i] * c[i]; k--)
                {
                    g[k] = std::min(g[k], g[k - c[i] * v[i]] + c[i]);
                }
            }
        }
        for (int i = t; i <= t + maxv2; i++)
        {
            ans = std::min(ans, f[i - t] + g[i]);
        }
        write(ans >= INF ? -1 : ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}