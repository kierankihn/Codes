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
    const int MAXN = 500 + 5;
    const int MAXN2 = MAXN * MAXN;
    int n;
    int a[MAXN2];
    int b[MAXN2];
    i64 sum[MAXN2];
    int lowbit(int x)
    {
        return x & (-x);
    }
    i64 query(int x)
    {
        i64 res = 0;
        while (x > 0)
        {
            res += sum[x], x -= lowbit(x);
        }
        return res;
    }
    void update(int x)
    {
        while (x < n * n)
        {
            sum[x]++, x += lowbit(x);
        }
    }
    i64 calc(int *x)
    {
        i64 res = 0;
        std::fill(sum + 1, sum + n * n + 1, 0);
        for (int i = n * n; i >= 1; i--)
        {
            if (x[i] != 0)
            {
                res += query(x[i]), update(x[i]);
            }
        }
        return res;
    }
    int main()
    {
        while (scanf("%d", &n) != EOF)
        {
            readAll(a + 1, a + n * n + 1);
            readAll(b + 1, b + n * n + 1);
            if (calc(a) % 2 == calc(b) % 2)
            {
                puts("TAK");
            }
            else
            {
                puts("NIE");
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