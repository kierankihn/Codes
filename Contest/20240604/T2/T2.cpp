/**
 * @author Kieran Kihn
 * @date 2024.06.04
 * @name CF542F
 * @link https://codeforces.com/contest/542/problem/F
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

    constexpr int MAXT = 1e2 + 5;
    constexpr int MAXN = 1e3 + 5;

    int n, t;

    int a[MAXN], b[MAXN];

    int c[MAXT][MAXN];

    int dp[MAXT][MAXN];

    int main()
    {
        read(n, t);
        for (int i = 1; i <= n; i++)
        {
            b[i] = std::max(0LL, t - readi() + 1), a[i] = readi();
            c[b[i]][++c[b[i]][0]] = a[i];
        }
        for (int i = 1; i <= t; i++)
        {
            std::sort(c[i] + 1, c[i] + c[i][0] + 1, std::greater<int>());
        }

        for (int i = t; i >= 1; i--)
        {
            for (int j = 1; j <= n + 1; j++)
            {
                for (int k = 0, sum = 0; k <= j && k <= c[i][0] + 1; sum += c[i][++k])
                {
                    dp[i][j] = std::max({dp[i][j], dp[i + 1][(j - k) * 2] + sum});
                }
            }
        }

        write(dp[1][1]);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}