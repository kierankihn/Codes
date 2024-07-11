/**
 * @author Kieran Kihn
 * @date 2024.07.06
 * @name C
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

    constexpr int MAXN = 2000 + 5;

    int n, k;
    i64 a[MAXN];

    i64 dp[MAXN];

    int check(i64 max)
    {
        for (i64 i = 1; i <= n; i++)
        {
            dp[i] = i - 1;
            for (i64 j = 1; j < i; j++)
            {
                if (std::abs(a[i] - a[j]) <= (i - j) * max)
                {
                    dp[i] = std::min(dp[i], dp[j] + i - j - 1);
                }
            }

            if (dp[i] + n - i <= k)
            {
                return true;
            }
        }

        return false;
    }

    int main()
    {
        read(n, k);
        readAll(a + 1, a + n + 1);

        i64 l = 0, r = 2e9;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        write(l);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}