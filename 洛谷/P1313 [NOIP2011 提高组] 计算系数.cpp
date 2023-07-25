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
    const LL MOD = 10007;
    LL a, b, k, n, m, ans;
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
            a = a % mod;
            b >>= 1;
        }
        return res;
    }
    LL factorial(LL a, LL mod)
    {
        if (a == 1)
        {
            return 1 % mod;
        }
        return factorial(a - 1, mod) * a % mod;
    }
    LL C(LL a, LL b, LL mod)
    {
        LL res = factorial(a, mod);
        LL tmp = factorial(a - b, mod) * factorial(b, mod) % mod;
        res *= qpow(tmp, mod - 2, mod);
        res = res % mod;
        return res;
    }
    int main()
    {
        using input::read;
        using output::write;
        read(a, b, k, n, m);
        ans = qpow(a, n, MOD) * qpow(b, m, MOD) % MOD;
        ans *= C(k, n, MOD);
        ans %= MOD;
        write(ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}