/**
 * @author Kieran Kihn
 * @date 2024.07.01
 * @name P6433 「EZEC-1」出题
 * @link https://www.luogu.com.cn/problem/P6433
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

    constexpr int MAXN = 1000 + 5;

    int n, m, k;
    int v[MAXN], w[MAXN];

    int dp[MAXN][MAXN];

    int ans = 0;

    int main()
    {
        read(n, m, k);
        for (int i = 1; i <= n; i++)
        {
            read(v[i], w[i]);
            w[0] += w[i], v[0] += v[i];
        }

        if (w[0] <= m)
        {
            std::sort(v + 1, v + n + 1, std::greater<int>());
            v[0] -= v[n];
            for (int i = 1; i <= k && i < n; i++)
            {
                v[0] += v[i];
            }
            write(v[0]);

            return 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= w[i]; j--)
            {
                for (int p = k; p >= 0; p--)
                {
                    dp[j][p] = std::max(dp[j][p], dp[j - w[i]][p] + v[i]);
                    if (p != 0)
                    {
                        dp[j][p] = std::max(dp[j][p], dp[j - w[i]][p - 1] + 2 * v[i]);
                    }
                    ans = std::max(ans, dp[j][p]);
                }
            }
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