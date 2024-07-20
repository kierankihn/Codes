/**
 * @author Kieran Kihn
 * @date 2024.07.15
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

    constexpr int MAXN = 3000 + 5;

    int n;
    int a[MAXN][3];

    int dp[MAXN][MAXN][4];

    int main()
    {
        std::memset(dp, 0x9f, sizeof(dp));

        read(n);
        for (int k = 0; k < 3; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                read(a[i][k]);
            }
        }

        dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = dp[0][0][3] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j][0] = std::max({dp[i - 1][j][1], dp[i - 1][j][3]}) + a[i][0];
                if (j - 1 >= 0)
                {
                    dp[i][j][1] = std::max({dp[i - 1][j - 1][1], dp[i - 1][j - 1][3]}) + a[i][1];
                    dp[i][j][2] = std::max({dp[i - 1][j - 1][0], dp[i - 1][j - 1][2]}) + a[i][1];
                }
                if (j - 2 >= 0)
                {
                    dp[i][j][3] = std::max({dp[i - 1][j - 2][0], dp[i - 1][j - 2][2]}) + a[i][2];
                }
            }
        }

        write(std::max({dp[n][n - 1][0], dp[n][n - 1][1], dp[n][n - 1][2]}));

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
} // Hydro