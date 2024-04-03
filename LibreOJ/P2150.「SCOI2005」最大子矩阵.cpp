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
    const int INF = 0x3f3f3f3f;
    const int MAXN = 100 + 5;
    const int MAXM = 2 + 5;
    const int MAXK = 10 + 5;
    int n, m, k;
    int a[MAXN][MAXM];
    i64 b[MAXN][MAXM];
    namespace subtask1
    {
        i64 dp[MAXN][MAXK];
        i64 solve()
        {
            std::fill(dp[0], dp[MAXN - 1] + MAXK, -INF), dp[0][0] = 0;
            for (int j = 0; j <= k; j++)
            {
                for (int i = 1; i <= n; i++)
                {
                    dp[i][j] = dp[i - 1][j];
                    if (j == 0)
                    {
                        continue;
                    }
                    for (int p = 0; p < i; p++)
                    {
                        dp[i][j] = std::max(dp[i][j], dp[p][j - 1] + b[i][1] - b[p][1]);
                    }
                }
            }
            return dp[n][k];
        }
    }
    namespace subtask2
    {
        i64 dp[MAXN][MAXN][MAXK];
        i64 solve()
        {
            std::fill(dp[0][0], dp[MAXN - 1][MAXN - 1] + MAXK, -INF), dp[0][0][0] = 0;
            for (int p = 0; p <= k; p++)
            {
                for (int i = 0; i <= n; i++)
                {
                    for (int j = 0; j <= n; j++)
                    {
                        if (i != 0)
                        {
                            dp[i][j][p] = std::max(dp[i][j][p], dp[i - 1][j][p]);
                        }
                        if (j != 0)
                        {
                            dp[i][j][p] = std::max(dp[i][j][p], dp[i][j - 1][p]);
                        }
                        if (p == 0)
                        {
                            continue;
                        }
                        for (int q = 0; q < std::max(i, j); q++)
                        {
                            if (q < i)
                            {
                                dp[i][j][p] = std::max(dp[i][j][p], dp[q][j][p - 1] + b[i][1] - b[q][1]);
                            }
                            if (q < j)
                            {
                                dp[i][j][p] = std::max(dp[i][j][p], dp[i][q][p - 1] + b[j][2] - b[q][2]);
                            }
                            if (i == j)
                            {
                                dp[i][j][p] = std::max(dp[i][j][p], dp[q][q][p - 1] + b[i][1] + b[j][2] - b[q][1] - b[q][2]);
                            }
                        }
                    }
                }
            }
            return dp[n][n][k];
        }
    }
    int main()
    {
        read(n, m, k);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                read(a[i][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                b[i][j] = b[i - 1][j] + a[i][j];
            }
        }
        if (m == 1)
        {
            write(subtask1::solve());
        }
        if (m == 2)
        {
            write(subtask2::solve());
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}