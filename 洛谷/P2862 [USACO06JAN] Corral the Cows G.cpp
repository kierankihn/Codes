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
    const int MAXN = 1000 + 5;
    const int INF  = 0x3f3f3f3f;
    int n, c;
    i64 ans = INF;
    i64 pos[MAXN][2];
    i64 p[MAXN * 10];
    i64 a[MAXN][MAXN];
    i64 sum[MAXN][MAXN];
    int main()
    {
        read(c, n);

        for (int i = 1; i <= n; i++)
        {
            read(pos[i][0], pos[i][1]);
            p[++p[0]] = pos[i][0], p[++p[0]] = pos[i][1];
        }

        std::sort(p + 1, p + p[0] + 1);
        p[0] = std::unique(p + 1, p + p[0] + 1) - p - 1;

        for (int i = 1; i <= n; i++)
        {
            pos[i][0] = std::lower_bound(p + 1, p + p[0] + 1, pos[i][0]) - p;
            pos[i][1] = std::lower_bound(p + 1, p + p[0] + 1, pos[i][1]) - p;
            a[pos[i][0]][pos[i][1]]++;
        }

        p[++p[0]] = INF;

        n = p[0] - 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int cl, ln;
                ln = i, cl = j;
                for (; ln <= n; ln++)
                {
                    while (p[cl] - p[j] + 1 < p[ln] - p[i] + 1)
                    {
                        cl++;
                    }
                    if (sum[ln][cl] - sum[i - 1][cl] - sum[ln][j - 1] + sum[i - 1][j - 1] >= c)
                    {
                        ans = std::min(ans, p[ln] - p[i] + 1);
                    }
                }
            }
        }

        write(ans);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}