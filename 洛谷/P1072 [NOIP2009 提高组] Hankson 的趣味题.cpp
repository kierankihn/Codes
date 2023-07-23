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
    typedef int LL;
    LL n;
    LL ans = 0;
    LL a, b, a0, a1, b0, b1;
    inline LL gcd(LL a, LL b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    int solve()
    {
        using input::read;
        using output::write;
        read(n);
        while (n--)
        {
            ans = 0;
            read(a0, a1, b0, b1);
            a = a0 / a1;
            b = b1 / b0;
            for (LL i = 1; i * i <= b1; i++)
            {
                int x = i, y = b1 / i;
                if (b1 % x != 0)
                {
                    continue;
                }
                if ((x % a1 == 0) && (gcd(x / a1, a) == 1) && (gcd(b, b1 / x) == 1))
                {
                    ans++;
                }
                if ((x != y) && (y % a1 == 0) && (gcd(y / a1, a) == 1) && (gcd(b, b1 / y) == 1))
                {
                    ans++;
                }
            }
            write(ans);
        }
        return 0;
    }
}
int main()
{
    solution::solve();
    return 0;
}