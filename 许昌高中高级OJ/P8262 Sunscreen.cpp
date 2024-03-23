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
    typedef std::pair<int, std::set<int>> pisi;
    const int MAXN = 3e3 + 5;
    int n, m;
    int ans = 0;
    pii cow[MAXN];
    pii bottle[MAXN];
    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(cow[i].first, cow[i].second);
        }
        for (int i = 1; i <= m; i++)
        {
            read(bottle[i].first, bottle[i].second);
        }
        std::sort(cow + 1, cow + n + 1, [](const pii &a, const pii &b)
                  { return a.second < b.second; });
        std::sort(bottle + 1, bottle + m + 1, [](const pii &a, const pii &b)
                  { return a.first < b.first; });
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (bottle[j].second != 0 && cow[i].first <= bottle[j].first && bottle[j].first <= cow[i].second)
                {
                    ans++, bottle[j].second--;
                    break;
                }
            }
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