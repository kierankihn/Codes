/**
 * @author Kieran Kihn
 * @date 2024.09.26
 * @name light
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
} // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;
    typedef std::pair<int, int> pii;

    constexpr int MAXN = 6e3 + 5;
    constexpr int MOD  = 1e9 + 7;

    int n;
    pii a[MAXN];

    i64 dp[MAXN][2];

    i64 ans = 0;

    int main()
    {
        std::freopen("light.in", "r", stdin);
        std::freopen("light.out", "w", stdout);

        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i].first, a[i].second);
        }

        std::sort(a + 1, a + n + 1);

        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = dp[i][1] = 1;
            for (int j = i - 1; j >= 1; j--)
            {
                if (a[j].second > a[i].second)
                {
                    dp[j][0] += dp[i][1], dp[j][0] %= MOD;
                }
                else
                {
                    dp[i][1] += dp[j][0], dp[i][1] %= MOD;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            ans += dp[i][0] + dp[i][1], ans %= MOD;
        }

        ans += MOD - n, ans %= MOD;

        write(ans);

        return 0;
    }
} // namespace solution
int main()
{
    solution::main();
    return 0;
}