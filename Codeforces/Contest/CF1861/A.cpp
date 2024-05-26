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
    using input::read;
    using output::write;
    LL n;
    LL t;
    LL getOneCnt(LL x)
    {
        LL res = 0;
        while (x)
        {
            if (x & 1)
            {
                res++;
            }
            x = x >> 1;
        }
        return res;
    }
    LL getValue(LL x)
    {
        LL tot = 1;
        LL res = 0;
        LL k = n;
        while (x)
        {
            if (x & 1)
            {
                res = res + (k % 10 * tot);
                tot = tot * 10;
            }
            x = x >> 1;
            k = k / 10;
        }
        return res;
    }
    LL qpow(LL a, LL b, LL c)
    {
        LL res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a;
                res = res % c;
            }
            b >>= 1;
            a = a * a % c;
        }
        return res;
    }
    bool checkPrime(LL x)
    {
        if (x < 3 || x % 2 == 0)
            return x == 2;
        LL u = x - 1, t = 0;
        while (u % 2 == 0)
            u /= 2, ++t;
        for (int i = 0; i < 20; ++i)
        {
            LL a = rand() % (x - 2) + 2, v = qpow(a, u, x);
            if (v == 1)
                continue;
            LL s;
            for (s = 0; s < t; ++s)
            {
                if (v == x - 1)
                    break;
                v = (long long)v * v % x;
            }
            if (s == t)
                return 0;
        }
        return 1;
    }
    int main()
    {
        read(t);
        while (t--)
        {
            read(n);
            bool flag = false;
            for (int i = 0; i <= (1 << 9) - 1; i++)
            {
                if (getOneCnt(i) >= 2 && checkPrime(getValue(i)))
                {
                    write(getValue(i));
                    flag = true;
                    break;
                }
            }
            if (flag == false)
            {
                write(-1);
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