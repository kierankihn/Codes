#include <bits/stdc++.h>
#include <unistd.h>
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
    const LL MAXN = 1e5 + 5;
    LL T;
    LL n, m, p;
    LL fac[MAXN];
    LL qpow(LL a, LL b, LL mod)
    {
        LL res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a;
                res %= mod;
            }
            a = a * a;
            a %= mod;
            b >>= 1;
        }
        return res;
    }
    LL factorial(LL a, LL mod)
    {
        if (fac[a])
        {
            return fac[a];
        }
        if (a == 0)
        {
            return 1;
        }
        return fac[a] = factorial(a - 1, mod) * a % mod;
    }
    LL C(LL a, LL b, LL mod)
    {
        if (b > a)
        {
            return 0;
        }
        return (factorial(a, mod) * qpow(factorial(b, mod), mod - 2, mod) % mod) * qpow(factorial(a - b, mod), mod - 2, mod) % mod;
    }
    LL lucas(LL a, LL b, LL mod)
    {
        return b == 0 ? 1 : (C(a % mod, b % mod, mod) * lucas(a / mod, b / mod, mod) % mod);
    }
    int main()
    {
        using input::read;
        using output::write;
        read(T);
        while (T--)
        {
            memset(fac, 0, sizeof(fac));
            read(n, m, p);
            write(lucas(n + m, n, p));
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}