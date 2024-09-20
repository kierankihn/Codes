/**
 * @author Kieran Kihn
 * @date 2024.09.19
 * @name star
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

    constexpr int MAXN = 5e5 + 5;
    constexpr int MOD  = 998244353;

    int n;

    std::vector<int> e[MAXN];

    int size[MAXN];

    i64 dp[4];

    i64 ans = 0;

    int dfs(int u, int fa)
    {
        size[u] = 1;
        for (auto v : e[u])
        {
            if (v != fa)
            {
                size[u] += dfs(v, u);
            }
        }
        return size[u];
    }

    void solve(int u, int fa)
    {
        dp[0] = 1, dp[1] = dp[2] = dp[3] = 0;
        for (auto v : e[u])
        {
            i64 sum = size[v];
            if (v == fa)
            {
                sum = n - size[u];
            }
            dp[3] = dp[3] * (sum + 1) + dp[2] * sum, dp[3] %= MOD;
            dp[2] = dp[2] + dp[1] * sum, dp[2] %= MOD;
            dp[1] = dp[1] + dp[0] * sum, dp[1] %= MOD;
        }

        ans += dp[3], ans %= MOD;

        for (auto v : e[u])
        {
            if (v != fa)
            {
                solve(v, u);
            }
        }
    }

    int main()
    {
        // freopen("star.in", "r", stdin);
        // freopen("star.out", "w", stdout);

        read(n);
        for (int i = 1; i < n; i++)
        {
            int u = readi(), v = readi();
            e[u].push_back(v), e[v].push_back(u);
        }

        dfs(1, 0), solve(1, 0);

        write(ans);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}