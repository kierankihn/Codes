/**
 * @author Kieran Kihn
 * @date 2024.06.07
 * @name CF855C
 * @link https://codeforces.com/contest/855/problem/C
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

    constexpr int MAXK = 10 + 5;
    constexpr int MAXN = 1e5 + 5;
    constexpr i64 MOD  = 1e9 + 7;

    i64 n, m;
    i64 k, x;

    std::vector<int> e[MAXN];

    i64 dp[MAXN][MAXK][3];  // 0: [1, k - 1], 1: k, 2: [k + 1, m]

    i64 ans = 0;

    void solve(int u, int fa)
    {
        dp[u][0][0] = k - 1, dp[u][1][1] = 1, dp[u][0][2] = m - k;

        for (auto v : e[u])
        {
            if (v == fa)
            {
                continue;
            }

            solve(v, u);

            for (int i = x; i >= 0; i--)
            {
                dp[u][i][0] = dp[u][i][0] * (dp[v][0][0] + dp[v][0][1] + dp[v][0][2]) % MOD;
                dp[u][i][1] = dp[u][i][1] * (dp[v][0][0]) % MOD;
                dp[u][i][2] = dp[u][i][2] * (dp[v][0][0] + dp[v][0][2]) % MOD;
                for (int j = 1; j <= i; j++)
                {
                    dp[u][i][0] += dp[u][i - j][0] * (dp[v][j][0] + dp[v][j][1] + dp[v][j][2]) % MOD;
                    dp[u][i][1] += dp[u][i - j][1] * (dp[v][j][0]) % MOD;
                    dp[u][i][2] += dp[u][i - j][2] * (dp[v][j][0] + dp[v][j][2]) % MOD;

                    dp[u][i][0] %= MOD, dp[u][i][1] %= MOD, dp[u][i][2] %= MOD;
                }
            }
        }
    }

    int main()
    {
        read(n, m);
        for (int i = 1; i < n; i++)
        {
            int u = readi(), v = readi();
            e[u].push_back(v), e[v].push_back(u);
        }
        read(k, x);

        solve(1, 0);

        for (int i = 0; i <= x; i++)
        {
            ans += dp[1][i][0] + dp[1][i][1] + dp[1][i][2], ans %= MOD;
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
 * 0: [1, k - 1], 1: k, 2: [k, m]
 * 0, 1, 2 -> 0
 * 0 -> 1
 * 0, 2 -> 2
 */