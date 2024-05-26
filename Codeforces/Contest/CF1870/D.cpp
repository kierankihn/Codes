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
    const int INF = 0x3f3f3f3f;
    using input::read;
    using output::write;
    int t;
    LL n, k;
    LL val[MAXN];
    LL ans = 0;
    int main()
    {
        read(t);
        while (t--)
        {
            ans = INF;
            read(n);
            for (int i = 1; i <= n; i++)
            {
                read(val[i]);
            }
            read(k);
            for (int i = n - 1; i >= 1; i--)
            {
                val[i] = std::min(val[i], val[i + 1]);
            }
            for (int i = 1; i <= n; i++)
            {
                if (val[i] != val[i - 1])
                {
                    ans = std::min(ans, k / (val[i] - val[i - 1]));
                    k -= ans * (val[i] - val[i - 1]);
                }
                printf("%lld%c", ans, (i != n) ? ' ' : '\n');
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