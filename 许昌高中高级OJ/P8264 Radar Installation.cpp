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
    typedef double dbi;
    typedef long long i64;
    typedef std::pair<int, int> pii;
    typedef std::pair<dbi, dbi> pdd;
    const int MAXN = 1e3 + 5;
    const int INF = 0x3f3f3f3f;
    const pdd ERR = {-INF, -INF};
    int t;
    int n, r;
    pii pos[MAXN];
    pdd range[MAXN];
    pdd calc(int a, int b)
    {
        i64 delta = 4 * (r * r - b * b);
        if (delta < 0)
        {
            return ERR;
        }
        return {a - (std::sqrt(delta) / 2), a + (std::sqrt(delta) / 2)};
    }
    i64 solve()
    {
        i64 res = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((range[i] = calc(pos[i].first, pos[i].second)) == ERR)
            {
                return -1LL;
            }
        }
        std::sort(range + 1, range + n + 1, [](const pdd &a, const pdd &b)
                  { return a.second == b.second ? a.first < b.first : a.second < b.second; });
        dbi pre = -INF;
        for (int i = 1; i <= n; i++)
        {
            if (pre < range[i].first)
            {
                pre = range[i].second, res++;
            }
        }
        return res;
    }
    int main()
    {
        while (read(n, r), (n != 0 && r != 0))
        {
            for (int i = 1; i <= n; i++)
            {
                read(pos[i].first, pos[i].second);
            }
            printf("Case %d: %lld\n", ++t, solve());
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}