#include <bits/stdc++.h>
namespace IO
{
    namespace basic_IO
    {
        template <typename T>
        void __read(T &x)
        {
            char ch;
            T res = 0, f = 1;
            while (std::isdigit(ch = getchar()) == false)
            {
                f = (ch != '-');
            }
            do
            {
                res = res * 10 + (ch - '0');
            } while (std::isdigit(ch = getchar()) == true);
            x = res * (f ? 1 : -1);
        }
        template <typename First, typename... Rest>
        void __read(First &first, Rest &...rest)
        {
            __read(first);
            __read(rest...);
        }
        template <typename T>
        void __write(T x)
        {
            if (x < 0)
            {
                std::putchar('-'), __write(-x);
                return;
            }
            if (x >= 10)
            {
                __write(x / 10);
            }
            std::putchar(x % 10 + '0');
        }
        template <typename First, typename... Rest>
        void __write(First first, Rest... rest)
        {
            __write(first), std::putchar(' '), __write(rest...);
        }
    }  // namespace basic_IO
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        basic_IO::__read(first, rest...);
    }
    template <typename T>
    void readAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__read(*i);
        }
    }
    template <typename First, typename... Rest>
    void write(First first, Rest... rest)
    {
        basic_IO::__write(first, rest...), std::putchar('\n');
    }
    template <typename T>
    void writeAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__write(*i);
        }
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;
    const int MAXN = 2e5 + 5;
    const i64 INF  = 1LL << 32LL;
    int t;
    int n;
    i64 s[MAXN], d[MAXN], e[MAXN];
    i64 calc(i64 x)
    {
        i64 res = 0;
        for (i64 i = 1; i <= n; i++)
        {
            if (x >= s[i])
            {
                res += (std::min(e[i], x) - s[i]) / d[i] + 1;
            }
        }
        return res;
    }
    int main()
    {
        read(t);
        while (t--)
        {
            read(n);
            for (int i = 1; i <= n; i++)
            {
                read(s[i], e[i], d[i]);
            }
            i64 l = 1, r = INF;
            while (l < r)
            {
                i64 mid = (l + r) >> 1;
                if (calc(mid) & 1)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }

            if (l == INF)
            {
                puts("Poor QIN Teng:( ");
            }
            else
            {
                write(l, calc(l) - calc(l - 1));
            }
        }
        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}