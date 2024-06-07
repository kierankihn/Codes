/**
 * @author Kieran Kihn
 * @date 2024.06.07
 * @name CF533B
 * @link https://codeforces.com/contest/533/problem/B
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

    constexpr int MAXN = 2e5 + 5;
    constexpr int INF  = 0x3f3f3f3f;

    int n;
    i64 a[MAXN];

    std::vector<int> e[MAXN];

    i64 dp[MAXN][2];  // 0 偶 1 奇

    void solve(int u)
    {
        for (auto v : e[u])
        {
            solve(v);
        }

        i64 sum = 0, flag = 0, max = -INF;
        for (auto v : e[u])
        {
            if (dp[v][0] > dp[v][1])
            {
                sum += dp[v][0];
            }
            else
            {
                sum += dp[v][1], flag += 1;
            }

            max = std::max(max, -std::abs(dp[v][0] - dp[v][1]));
        }

        flag = flag & 1;

        dp[u][flag] = sum, dp[u][flag ^ 1] = sum + max;
        dp[u][1] = std::max(dp[u][1], dp[u][0] + a[u]);
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            i64 fa = readi(), v = readi();
            if (fa != -1)
            {
                e[fa].push_back(i);
            }
            a[i] = v;
        }

        solve(1);

        write(std::max(dp[1][0], dp[1][1]));

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}