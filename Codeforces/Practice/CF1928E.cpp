/**
 * @author Kieran Kihn
 * @date 2024.06.13
 * @name CF1928E
 * @link https://codeforces.com/contest/1928/problem/E
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

    constexpr int MAXS = 2e5 + 5;
    constexpr int INF  = 0x3f3f3f3f;

    int t;

    i64 n, x, y, s, res;

    int dp[MAXS];

    void init()
    {
        std::fill(dp, dp + MAXS, INF), dp[0] = 0;
        for (int i = 0; i < MAXS; i++)
        {
            for (int j = 1; i + j * (j - 1) / 2 < MAXS; j++)
            {
                dp[i + j * (j - 1) / 2] = std::min(dp[i + j * (j - 1) / 2], dp[i] + j);
            }
        }
    }

    void print_sequece(int sum, int len)
    {
        if (sum == 0)
        {
            for (int i = 1; i <= len; i++)
            {
                printf("%lld ", x % y);
            }
            return;
        }

        i64 i = 1;
        for (; i * (i - 1) / 2 <= sum; i++)
        {
            if (dp[sum] == dp[sum - i * (i - 1) / 2] + i)
            {
                print_sequece(sum - i * (i - 1) / 2, len - i);
                break;
            }
        }

        for (int now = x % y; i > 0; i--, now += y)
        {
            printf("%d ", now);
        }
    }
    void print(i64 first)
    {
        for (int i = 1, now = x; i <= first; i++, now += y)
        {
            printf("%d ", now);
        }
        print_sequece(s / y - first * (first - 1) / 2, n - first), write("\n");
    }

    int main()
    {
        init();

        read(t);
        while (t--)
        {
            res = 0;

            read(n, x, y, s);

            s -= x % y * n;

            for (i64 i = 1; i <= n; i++)
            {
                s -= x / y * y;
                if (s / y - i * (i - 1) / 2 >= 0 && s % y == 0)
                {
                    if (dp[s / y - i * (i - 1) / 2] + i <= n)
                    {
                        res = 1;

                        write("YES");
                        print(i);

                        break;
                    }
                }
            }

            if (res == 0)
            {
                write("NO");
            }
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
 * {a}: {x, x + y, x + 2 * y, x + 3 * y}
 * \sum {a_i}: x * len + len * (len - 1) * y / 2
 * s -= x mod y * n
 * {a}_1: x - x mod y <=> x / y * y
 * {a}_k: 0
 *
 * s -= x mod y * n, s -= x / y * y * len_1 <=> s / y = len * (len - 1) / 2
 *
 * dp[i][j]: 和为 i, 最后一段长度为 j
 * dp[i][j] -> dp[i + k * (k - 1) / 2][k] (k >= j)
 */