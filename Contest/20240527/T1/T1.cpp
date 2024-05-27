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
    long long readi()
    {
        long long res;
        read(res);
        return res;
    }
    std::string reads()
    {
        std::string res;
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
}  // namespace IO
namespace solution
{
#define dp(x, y) (dp[x][y + DELTA])

    using namespace IO;
    typedef long long i64;

    constexpr int DELTA = 1e5;
    constexpr int MAXN  = 3e2 + 5;
    constexpr int MAXA  = 2e5 + 5;
    constexpr int MOD   = 998244353;

    int n;
    int a[MAXN];

    int dp[MAXN][MAXA];

    int ans = 0;

    int main()
    {
        read(n), readAll(a + 1, a + n + 1);

        dp(1, a[2]) = 1;
        for (int i = 1; i <= n - 2; i++)
        {
            for (int j = -9e4; j <= 9e4; j++)
            {
                if (j != 0)
                {
                    dp(i + 1, a[i + 2] + j) += dp(i, j), dp(i + 1, a[i + 2] + j) %= MOD;
                    dp(i + 1, a[i + 2] - j) += dp(i, j), dp(i + 1, a[i + 2] - j) %= MOD;
                }
                else
                {
                    dp(i + 1, a[i + 2]) += dp(i, j), dp(i + 1, a[i + 2]) %= MOD;
                }
            }
        }

        for (int j = -DELTA; j <= DELTA; j++)
        {
            ans += dp(n - 1, j), ans %= MOD;
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

/**
 * dp[i][j] -> dp[i + 1][j + a[i + 2]]
 * dp[i][j] -> dp[i + 1][j - a[i + 2]]
 */