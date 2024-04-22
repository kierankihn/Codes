#include <bits/stdc++.h>
namespace IO
{
    namespace basic_IO
    {
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value>::type __read(T &x)
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
        template <typename T>
        typename std::enable_if<!std::is_integral<T>::value>::type __read(T &x)
        {
            std::cin >> x;
        }
        template <typename First, typename... Rest>
        void __read(First &first, Rest &...rest)
        {
            __read(first);
            __read(rest...);
        }
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value>::type __write(T x)
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
        template <typename T>
        typename std::enable_if<!std::is_integral<T>::value>::type __write(T x)
        {
            std::cout << x;
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
    typedef double dbi;
    typedef long long i64;

    const int MAXN = 1e6 + 5;
    const i64 INF  = 0x3f3f3f3f;

    struct pii
    {
        i64 first, second;
    };
    bool operator<(const pii &a, const pii &b)
    {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    }

    int n;
    pii p[MAXN];
    dbi ans = INF;

    dbi calc(const pii &a, const pii &b)
    {
        return std::sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
    }

    void solve(int l, int r)
    {
        if (l == r)
        {
            return;
        }

        i64 mid = (l + r) >> 1;
        solve(l, mid), solve(mid + 1, r);

        std::sort(p + l, p + r + 1);
        auto h = p[mid].first;

        auto begin = std::lower_bound(p + l, p + r + 1, pii{h - i64(std::ceil(ans)), -INF}),
             end   = std::upper_bound(p + l, p + r + 1, pii{h + i64(std::ceil(ans)), INF});
        std::sort(begin, end, [](const pii &a, const pii &b)
                  { return a.second < b.second || (a.second == b.second && a.first < b.first); });

        auto prev = begin, next = begin;
        for (auto i = begin; i != end; i++)
        {
            while (prev->second < i->second - ans && prev != end)
            {
                prev++;
            }
            while (next->second < i->second + ans && next != end)
            {
                next++;
            }
            for (auto j = prev; j != next; j++)
            {
                if (i != j)
                {
                    ans = std::min(ans, calc(*i, *j));
                }
            }
        }
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(p[i].first, p[i].second);
        }

        std::sort(p + 1, p + n + 1);

        solve(1, n);

        std::printf("%.4lf\n", ans);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}