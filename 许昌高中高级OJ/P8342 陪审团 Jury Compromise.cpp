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
    typedef std::pair<int, int> pii;

    const int MAXN  = 100 + 5;
    const int MAXM  = 20 + 5;
    const int MAXW  = MAXN * MAXM * 2;
    const int DELTA = MAXN * MAXM;
    const int INF   = 0x3f3f3f3f;

    int n, m;
    int p[MAXN];
    int d[MAXN];
    pii ans = {-INF, INF};

    int dp[MAXM][MAXW];

    int main()
    {
        while (read(n, m), n != 0 || m != 0)
        {
            for (int i = 1; i <= n; i++)
            {
                read(p[i], d[i]);
            }

            std::fill(dp[0], dp[MAXM - 1] + MAXW, -INF);
            for (int i = 1; i <= n; i++)
            {
                dp[0][DELTA] = 0;
                for (int j = m; j >= 1; j--)
                {
                    for (int k = DELTA - n * m; k <= DELTA + n * m; k++)
                    {
                        // dp[i][j][k] = std::max(dp[i - 1][j][k], dp[i - 1][j - 1][k + p[i] - d[i]] + p[i] + d[i]);
                        dp[j][k] = std::max(dp[j][k], dp[j - 1][k + p[i] - d[i]] + p[i] + d[i]);
                    }
                }
            }

            for (int i = 0; i <= n * m; i++)
            {
                if (dp[m][DELTA + i] >= 0 || dp[m][DELTA - i] >= 0)
                {
                    if (dp[m][DELTA + i] > dp[m][DELTA - i])
                    {
                        write((dp[m][DELTA + i] + i) / 2, (dp[m][DELTA + i] - i) / 2);
                    }
                    else
                    {
                        write((dp[m][DELTA - i] + i) / 2, (dp[m][DELTA - i] - i) / 2);
                    }
                    std::exit(0);
                }
            }

            // TODO(kierankihn): 添加方案输出
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}