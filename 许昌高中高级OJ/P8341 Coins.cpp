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

    const int MAXN = 100 + 5;
    const int MAXM = 1e5 + 5;
    const int INF  = 0x3f3f3f3f;

    int n, m;
    int ans = 0;
    int a[MAXN], c[MAXN];

    bool dp[MAXN][MAXM];

    int main()
    {
        while (read(n, m), n != 0 || m != 0)
        {
            ans = 0;
            std::memset(dp, 0, sizeof(dp));

            readAll(c + 1, c + n + 1), readAll(a + 1, a + n + 1);

            for (int i = 1; i <= n; i++)
            {
                dp[i - 1][0] = 1;
                for (int x = 0; x < c[i]; x++)
                {
                    int last = -INF;
                    for (int y = 0; x + y * c[i] <= m; y++)
                    {
                        if (dp[i - 1][x + y * c[i]])
                        {
                            last = x + y * c[i];
                        }
                        dp[i][x + y * c[i]] = last >= x + (y - a[i]) * c[i];
                    }
                }
            }

            for (int i = 1; i <= m; i++)
            {
                ans += dp[n][i];
            }

            write(ans);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}