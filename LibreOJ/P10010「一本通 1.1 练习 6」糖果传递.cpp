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
}
namespace solution
{
    using namespace IO;
    typedef long long i64;
    const int MAXN = 1e6 + 5;
    int n;
    i64 ans = 0;
    i64 a[MAXN];
    i64 b[MAXN];
    i64 c[MAXN];
    int main()
    {
        read(n), readAll(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            b[i] = b[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            c[i] = b[n] / n * i - b[i];
        }
        std::sort(c + 1, c + n + 1);
        for (int i = 1; i <= n; i++)
        {
            ans += std::abs(c[i] - c[n / 2 + 1]);
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