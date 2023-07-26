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
    const int MAXN = 3000 + 5;
    const int MOD = 1e5 + 3;
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
            a = a % mod;
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
            return fac[a] = 1;
        }
        return fac[a] = factorial(a - 1, mod) * a % mod;
    }
    LL C(LL a, LL b, LL mod)
    {
        return factorial(a, mod) * qpow(factorial(b, mod), mod - 2, mod) % mod * qpow(factorial(a - b, mod), mod - 2, mod) % mod;
    }
    LL solve(LL n, LL m, LL k, LL mod)
    {
        if (k > n || k > m)
        {
            return 0;
        }
        return C(n, k, mod) * C(m, k, mod) % mod * factorial(k, mod) % mod;
    }
    int main()
    {
        using input::read;
        using output::write;
        LL a, b, c, d, k, ans = 0;
        read(a, b, c, d, k);
        for (int i = 0; i <= k; i++)
        {
            ans += (solve(a, b, i, MOD) * solve(a + c - i, d, k - i, MOD)) % MOD;
            ans %= MOD;
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