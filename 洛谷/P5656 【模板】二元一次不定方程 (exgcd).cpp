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
    LL T;
    LL cnt;
    LL gcdab;
    LL a, b, c;
    LL a_, b_, c_;
    LL x0, y0, x1, y1;
    LL minx, maxx, miny, maxy;
    LL exgcd(LL a, LL b, LL &x, LL &y)
    {
        if (!b)
        {
            x = 1, y = 0;
            return a;
        }
        int d = exgcd(b, a % b, x, y);
        int t = x;
        x = y, y = t - (a / b) * y;
        return d;
    }
    void init()
    {
        cnt = gcdab = a = b = c = a_ = b_ = c_ = x0 = x1 = y0 = y1 = minx = miny = maxx = maxy = 0;
    }
    int solve()
    {
        using input::read;
        using output::write;
        read(T);
        while (T--)
        {
            init();
            read(a, b, c);
            gcdab = std::__gcd(a, b);
            if (c % gcdab != 0)
            {
                write(-1);
                continue;
            }
            a_ = a / gcdab, b_ = b / gcdab, c_ = c / gcdab;
            exgcd(a_, b_, x0, y0);
            x1 = x0 * c_, y1 = y0 * c_;
            minx = (x1 > 0 && x1 % b_ != 0) ? x1 % b_ : x1 % b_ + b_;
            maxy = (c_ - minx * a_) / b_;
            miny = (y1 > 0 && y1 % a_ != 0) ? y1 % a_ : y1 % a_ + a_;
            maxx = (c_ - miny * b_) / a_;
            if (maxx > 0)
            {
                cnt = (maxx - minx) / b_ + 1;
            }
            if (cnt)
            {
                write(cnt, minx, miny, maxx, maxy);
            }
            else
            {
                write(minx, miny);
            }
        }
        return 0;
    }
}

int main()
{
    solution::solve();
    return 0;
}