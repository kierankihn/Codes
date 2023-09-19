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
    using input::read;
    using output::write;
    int t;
    int n, m;
    int min = 0, max = 0;
    int a[MAXN], b[MAXN];
    int main()
    {
        read(t);
        while (t--)
        {
            min = max = 0;
            read(n, m);
            for (int i = 1; i <= n; i++)
            {
                read(a[i]);
                max = max ^ a[i], min = min ^ a[i];
            }
            for (int i = 1; i <= m; i++)
            {
                read(b[i]);
                if (n % 2 == 0)
                {
                    min = min & (~b[i]);
                }
                else
                {
                    max = max | b[i];
                }
            }
            write(min, max);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}