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
    typedef std::pair<int, int> pii;
    const int MAXN = 1e6 + 5;
    int n, m, t;
    i64 ans = 0;
    pii pos[MAXN];
    i64 a[MAXN], b[MAXN], c[MAXN];
    i64 solve(int size)
    {
        i64 res = 0;
        std::fill(b + 1, b + size + 1, 0), std::fill(c + 1, c + size + 1, 0);
        for (int i = 1; i <= size; i++)
        {
            b[i] = b[i - 1] + a[i];
        }
        for (int i = 1; i <= size; i++)
        {
            c[i] = b[size] / size * i - b[i];
        }
        std::sort(c + 1, c + size + 1);
        for (int i = 1; i <= size; i++)
        {
            res += std::abs(c[i] - c[size / 2 + 1]);
        }
        return res;
    }
    int main()
    {
        read(n, m, t);
        for (int i = 1; i <= t; i++)
        {
            read(pos[i].first, pos[i].second);
        }
        if (t % n == 0 && t % m == 0)
        {
            printf("both ");
        }
        else if (t % n == 0)
        {
            printf("row ");
        }
        else if (t % m == 0)
        {
            printf("column ");
        }
        else
        {
            printf("impossible ");
            exit(0);
        }
        if (t % n == 0)
        {
            std::fill(a + 1, a + n + 1, 0);
            for (int i = 1; i <= t; i++)
            {
                a[pos[i].first]++;
            }
            ans += solve(n);
        }
        if (t % m == 0)
        {
            std::fill(a + 1, a + m + 1, 0);
            for (int i = 1; i <= t; i++)
            {
                a[pos[i].second]++;
            }
            ans += solve(m);
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