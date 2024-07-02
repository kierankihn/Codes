/**
 * @author Kieran Kihn
 * @date 2024.06.28
 * @name T3
 * @link
 */
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
    using namespace IO;
    typedef long long i64;

    constexpr int MAXN  = 100 + 5;
    constexpr int MAX2X = (1 << 9) + 5;
    constexpr int MOD   = 998244353;

    int n, x;

    i64 fac[MAXN], inv[MAXN];

    i64 dp[MAXN][MAXN][MAX2X];

    i64 ans = 0;

    i64 qpow(i64 a, i64 b, i64 c = MOD)
    {
        i64 res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a % c;
            }
            a = a * a % c, b >>= 1;
        }
        return res;
    }
    void init()
    {
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fac[i] = fac[i - 1] * i % MOD;
        }
        inv[n] = qpow(fac[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--)
        {
            inv[i] = inv[i + 1] * (i + 1) % MOD;
        }
    }

    i64 C(i64 x, i64 y)
    {
        return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
    }

    int main()
    {
        read(n, x);

        init();

        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                for (int k = 0; k < (1 << (2 * x - 1)); k++)
                {
                    if ((k << 1 | 1) < (1 << (2 * x - 1)))
                    {
                        dp[i][j][k] = (dp[i - 1][j][k << 1] + dp[i - 1][j][k << 1 | 1]) % MOD;
                    }
                    for (int p = std::max(1 - i, 1 - x); p < x && j != 0; p++)
                    {
                        if ((k & (1 << (p + x - 1))) && (((k ^ (1 << (p + x - 1))) << 1 | 1) < (1 << (2 * x - 1))))
                        {
                            dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][(k ^ (1 << (p + x - 1))) << 1] + dp[i - 1][j - 1][(k ^ (1 << (p + x - 1))) << 1 | 1]) % MOD;
                        }
                    }
                }
            }
        }

        for (int i = 0; i <= n; i++)
        {
            i64 res = 0;
            for (int j = 0; j < (1 << x); j++)
            {
                res = res + dp[n][i][j] * fac[n - i] % MOD, res %= MOD;
            }
            res = res * ((i & 1) ? -1 : 1) % MOD, res %= MOD, res += MOD, res %= MOD;
            ans = ans + res, ans %= MOD;
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
