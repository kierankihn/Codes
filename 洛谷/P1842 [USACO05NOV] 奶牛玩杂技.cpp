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
        void __write(First &first, Rest &...rest)
        {
            __write(first), std::putchar(' '), __write(rest...);
        }
    }
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
    void write(First &first, Rest &...rest)
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
}
namespace solution
{
    using namespace IO;
    typedef long long i64;
    typedef std::pair<i64, i64> pll;
    const int MAXN = 5e4 + 5;
    const i64 INF = 0x3f3f3f3f;
    int n;
    i64 sum = 0;
    i64 ans = -INF;
    pll a[MAXN];
    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i].first, a[i].second);
        }
        std::sort(a + 1, a + n + 1, [](const pll &a, const pll &b)
                  { return a.first + a.second < b.first + b.second; });
        for (int i = 1; i <= n; i++)
        {
            ans = std::max(ans, sum - a[i].second);
            sum += a[i].first;
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