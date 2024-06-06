/**
 * @author Kieran Kihn
 * @date 2024.05.31
 * @name AGC004B
 * @link https://atcoder.jp/contests/agc004/tasks/agc004_b
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

    constexpr int MAXN = 2e3 + 5;
    constexpr i64 INF  = 0x3f3f3f3f3f3f3f3f;

    i64 n, x;

    i64 ans = INF;

    i64 a[MAXN];
    i64 min[MAXN][MAXN];

    int add(int x, int y)
    {
        return x + y <= n ? x + y : x + y - n;
    }

    int main()
    {
        std::memset(min, 0x3f, sizeof(min));

        read(n, x), readAll(a + 1, a + n + 1);

        for (int i = 1; i <= n; i++)
        {
            min[i][0] = a[i];
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                min[i][j] = std::min(min[i][j - 1], a[add(i, j)]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            i64 sum = i * x;

            for (int j = 1; j <= n; j++)
            {
                sum += min[j][i];
            }

            ans = std::min(ans, sum);
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