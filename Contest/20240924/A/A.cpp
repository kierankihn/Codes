#ifndef LOCAL
#pragma GCC optimize(3)
#endif
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
    } // namespace basic_IO
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
    long long readi()
    {
        long long res;
        read(res);
        return res;
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
            basic_IO::__write(*i), std::putchar(' ');
        }
        std::putchar('\n');
    }
} // namespace IO
namespace solution
{
    using namespace IO;
    typedef __int128 i128;

    constexpr int MAXV    = 10 + 5;
    constexpr int MAXN    = 1e3 + 5;
    constexpr int MAXLOGN = 10 + 5;

    int t;

    int n, m;
    i128 a[MAXN], b[MAXN];

    int p[MAXN][MAXV], cnt[MAXN][MAXV];
    int dp[MAXN][MAXN];

    int orsum[MAXN][MAXLOGN];
    int calc(i128 x)
    {
        int res = 0;
        if (x == 0)
        {
            res |= 1;
        }
        while (x)
        {
            res |= (1 << (x % 10)), x /= 10;
        }
        return res;
    }
    void build()
    {
        for (int i = 1; i <= n; i++)
        {
            orsum[i][0] = b[i] = calc(a[i]);
        }
        for (int k = 1; (1 << k) <= n; k++)
        {
            for (int l = 1, r = (1 << k); r <= n; l++, r++)
            {
                orsum[l][k] = orsum[l][k - 1] | orsum[l + (1 << (k - 1))][k - 1];
            }
        }
    }
    int query(int l, int r)
    {
        int k = std::__lg(r - l + 1);
        return orsum[l][k] | orsum[r - (1 << k) + 1][k];
    }

    int main()
    {
        read(t);
        while (t--)
        {
            read(n, m);
            readAll(a + 1, a + n + 1);

            build();
            for (int j = 0; j < 10; j++)
            {
                p[0][j] = 1;
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (b[i] & (1 << j))
                    {
                        p[i][j] = i;
                    }
                    else
                    {
                        p[i][j] = p[i - 1][j];
                    }

                    cnt[i][j] = __builtin_popcount(query(p[i][j], i));
                }
            }

            std::memset(dp, 0, sizeof(dp));
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    for (int k = 0; k < 10; k++)
                    {
                        dp[i][j] = std::max(dp[i][j], dp[p[i][k] - 1][j - 1] + cnt[i][k]);
                    }
                }
            }

            write(dp[n][m]);
        }

        return 0;
    }
} // namespace solution
int main()
{
    solution::main();
    return 0;
}