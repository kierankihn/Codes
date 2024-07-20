/**
 * @author Kieran Kihn
 * @date 2024.07.17
 * @name B
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

    constexpr int MAXN = 1e3 + 5;

    int n, m, p;
    int a[MAXN][MAXN];

    int sum[MAXN], cnt[MAXN];

    i64 dp[MAXN][MAXN];

    int main()
    {
        read(n, m, p);
        for (int i = 1; i <= m; i++)
        {
            auto s = reads();
            for (int j = 1; j <= n; j++)
            {
                sum[j] += a[i][j] = s[j - 1] - '0';
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cnt[sum[i]]++;
        }

        dp[cnt[1]][cnt[0]] = 1;

        for (int i = m + 1; i <= n; i++)
        {
            for (int j = 0, k = n - i + 1; k >= 0; j += 2, k -= 1)
            {
                if (k >= 2)
                {
                    dp[j + 2][k - 2] += dp[j][k] * k * (k - 1) / 2, dp[j + 2][k - 2] %= p;
                }
                if (k >= 1)
                {
                    dp[j][k - 1] += dp[j][k] * j * k, dp[j][k - 1] %= p;
                }
                if (j >= 2)
                {
                    dp[j - 2][k] += dp[j][k] * j * (j - 1) / 2, dp[j - 2][k] %= p;
                }
            }
        }

        write(dp[0][0]);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}
/** 
dp[j][k] -> dp[j + 2][k - 2] * C(k, 2)
dp[j][k] -> dp[j][k - 1] * C(j, 1) * C(k, 1)
dp[j][k] -> dp[j - 2][k] * C(j, 2)
  */