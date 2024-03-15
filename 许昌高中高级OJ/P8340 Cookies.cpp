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
        void __write(First &first, Rest &...rest)
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
    void write(First &first, Rest &...rest)
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
    typedef std::pair<i64, i64> pll;
    const int MAXN = 30 + 5;
    const int MAXM = 5e3 + 5;
    int n, m;
    pll g[MAXN];
    i64 s[MAXN];
    i64 dp[MAXN][MAXM];
    pii from[MAXN][MAXM];
    int ans[MAXN];
    void print(int i, int j)
    {
        if (i == 0 || j == 0)
        {
            return;
        }
        for (int now = 1; now <= i; now++)
        {
            ans[now]++;
        }
        print(from[i][j].first, from[i][j].second);
    }
    int main()
    {
        std::memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(g[i].first), g[i].second = i;
        }
        std::sort(g + 1, g + n + 1, std::greater<pll>());
        for (int i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] + g[i].first;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= m; j++)
            {
                for (int k = 0; k <= i; k++)
                {
                    if (dp[k][j - i] + k * (s[i] - s[k]) < dp[i][j])
                    {
                        from[i][j] = {k, j - i};
                        dp[i][j] = dp[k][j - i] + k * (s[i] - s[k]);
                    }
                }
            }
        }
        print(n, m);
        write(dp[n][m]);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (g[j].second == i)
                {
                    basic_IO::__write(ans[j]), putchar(' ');
                }
            }
        }
        putchar('\n');
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}