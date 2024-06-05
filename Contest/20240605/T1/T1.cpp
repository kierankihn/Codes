/**
 * @author Kieran Kihn
 * @date 2024.06.05
 * @name CF82D
 * @link https://codeforces.com/contest/82/problem/D
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
    typedef std::pair<int, int> pii;

    constexpr int MAXN = 1e3 + 5;
    constexpr i64 INF  = 0x3f3f3f3f3f3f3f3f;

    int n;
    i64 a[MAXN];

    i64 dp[MAXN][MAXN];
    pii from[MAXN][MAXN];

    i64 ans = INF;
    pii pos = {0, 0};

    void print(pii now)
    {
        pii next = from[now.first][now.second];

        if (now != pii(3, 1))
        {
            print(next);
        }

        if (now.second == next.second)
        {
            write(next.first - 1, next.first);
        }
        if (now.second == next.first - 1)
        {
            write(next.second, next.first);
        }
        if (now.second == next.first)
        {
            write(next.second, next.first - 1);
        }
    }

    int main()
    {
        std::memset(dp, 0x3f, sizeof(dp));

        read(n), readAll(a + 1, a + n + 1);

        if (n == 1)
        {
            write(a[1]), write(1);
            return 0;
        }
        if (n == 2)
        {
            write(std::max(a[1], a[2])), write(1, 2);
            return 0;
        }

        dp[3][1] = 0;
        for (int i = 3; i <= n; i += 2)
        {
            for (int j = 1; j < i - 1; j++)
            {
                if (dp[i + 2][j] > dp[i][j] + std::max(a[i - 1], a[i]))
                {
                    dp[i + 2][j] = dp[i][j] + std::max(a[i - 1], a[i]), from[i + 2][j] = {i, j};
                }
                if (dp[i + 2][i - 1] > dp[i][j] + std::max(a[j], a[i]))
                {
                    dp[i + 2][i - 1] = dp[i][j] + std::max(a[j], a[i]), from[i + 2][i - 1] = {i, j};
                }
                if (dp[i + 2][i] > dp[i][j] + std::max(a[j], a[i - 1]))
                {
                    dp[i + 2][i] = dp[i][j] + std::max(a[j], a[i - 1]), from[i + 2][i] = {i, j};
                }
            }
        }

        if (n & 1)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dp[n + 2][j] + a[j] < ans)
                {
                    ans = dp[n + 2][j] + a[j], pos = {n + 2, j};
                }
            }
            write(ans);
            print(pos);
            write(pos.second);
        }
        else
        {
            for (int j = 1; j < n; j++)
            {
                if (dp[n + 1][j] + std::max(a[j], a[n]) < ans)
                {
                    ans = dp[n + 1][j] + std::max(a[j], a[n]), pos = {n + 1, j};
                }
            }
            write(ans);
            print(pos);
            write(pos.second, n);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}
/**
 * dp[i][j] 第 i - 1, i 个人走进来，前边剩了一个 j 的最小花费
 * j >= i - 2: dp[i][j] <- dp[i - 2][k] (1 <= k < i - 2)
 * j < i -2  : dp[i][j] <- dp[i - 2][j]
 *
 * dp[i][j] -> dp[i + 2][j], dp[i + 2][i - 1], dp[i + 2][i - 2]
 */