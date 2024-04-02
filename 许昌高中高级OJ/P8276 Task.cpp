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
    typedef std::pair<i64, i64> pii;
    const int MAXN = 1e5 + 5;
    const int MAXP = 100 + 5;
    int n, m;
    i64 cnt = 0;
    i64 ans = 0;
    pii mach[MAXN];
    pii task[MAXN];
    std::multiset<i64> p[MAXP];
    i64 calc(pii x)
    {
        return x.first * 500 + x.second * 2;
    }
    int main()
    {
        while (scanf("%d%d", &n, &m) != EOF)
        {
            cnt = ans = 0;
            for (auto i : p)
            {
                i.clear();
            }
            for (int i = 1; i <= n; i++)
            {
                read(mach[i].first, mach[i].second);
                p[mach[i].second].insert(mach[i].first);
            }
            for (int i = 1; i <= m; i++)
            {
                read(task[i].first, task[i].second);
            }
            std::sort(task + 1, task + m + 1, [](const pii &a, const pii &b)
                      { return a.first > b.first || (a.first == b.first && a.second > b.second); });
            for (int i = 1; i <= m; i++)
            {
                auto now = task[i];
                for (int j = now.second; j <= 100; j++)
                {
                    if (p[j].empty() || task[i].first > *(--p[j].end()))
                    {
                        continue;
                    }
                    p[j].erase(p[j].lower_bound(now.first)), ans += calc(now), cnt++;
                    break;
                }
            }
            write(cnt, ans);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}