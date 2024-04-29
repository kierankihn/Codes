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
            basic_IO::__write(*i), std::putchar(' ');
        }
        std::putchar('\n');
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;
    typedef std::pair<i64, i64> pii;

    const int MAXN = 1e3 + 5;
    const int MOD  = 1e9 + 7;
    const int INF  = 0x3f3f3f3f;

    int t;
    int id;
    int n, m;
    i64 ans = 0;
    i64 a[MAXN];

    int size;
    i64 b[MAXN];

    i64 dp[MAXN][MAXN];

    i64 sum[MAXN];
    int lowbit(int x)
    {
        return x & (-x);
    }
    i64 query(int x)
    {
        i64 res = 0;

        while (x)
        {
            res += sum[x], res %= MOD, x -= lowbit(x);
        }

        return res;
    }
    void update(int x, i64 v)
    {
        while (x <= n)
        {
            sum[x] += v, sum[x] %= MOD, x += lowbit(x);
        }
    }

    int main()
    {
        read(t);
        while (id++, t--)
        {
            std::memset(dp, 0, sizeof(dp)), dp[0][0] = 1;

            read(n, m);

            a[0] = b[0] = -INF;
            for (int i = 1; i <= n; i++)
            {
                read(a[i]), b[i] = a[i];
            }

            std::sort(b, b + n + 1), std::unique(b, b + n + 1);

            for (int i = 0; i <= n; i++)
            {
                a[i] = std::lower_bound(b, b + n + 1, a[i]) - b + 1;
            }

            for (int j = 1; j <= m; j++)
            {
                std::fill(sum, sum + n + 1, 0);
                update(a[j - 1], dp[j - 1][j - 1]);

                for (int i = j; i <= n; i++)
                {
                    dp[i][j] = query(a[i] - 1);
                    update(a[i], dp[i][j - 1]);
                }
            }

            ans = 0;
            for (int i = m; i <= n; i++)
            {
                ans += dp[i][m], ans %= MOD;
            }

            printf("Case #%d: %lld\n", id, ans);
        }
        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}