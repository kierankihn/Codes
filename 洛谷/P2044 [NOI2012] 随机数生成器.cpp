#include <bits/stdc++.h>
using namespace std;
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
    typedef __int128 LL;
    LL ans = 0;
    LL x0, m, a, c, n, g;
    LL qpow(LL a, LL b, LL mod)
    {
        LL res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a % mod;
            }
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    LL solve(LL x)
    {
        if (x == 0)
        {
            return 1;
        }
        LL tmp, res = 0;
        if (!(x & 1))
        {
            tmp = solve((x >> 1) - 1);
            res = tmp * (qpow(a, x >> 1, m) + 1) + qpow(a, x, m);
            res %= m;
        }
        else
        {
            tmp = solve(x >> 1);
            res = tmp * (qpow(a, (x >> 1) + 1, m) + 1);
            res %= m;
        }
        return res;
    }
    int main()
    {
        using input::read;
        using output::write;
        read(m, a, c, x0, n, g);
        ans = solve(n - 1) * c;
        ans %= m;
        ans += qpow(a, n, m) * x0 % m;
        ans %= m;
        ans %= g;
        write(ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}