/**
 * @author Kieran Kihn
 * @date 2024.07.01
 * @name P2714 四元组统计
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

    constexpr int N    = 1e4;
    constexpr int MAXN = 1e4 + 5;

    int n;
    int a[MAXN];

    i64 sum[MAXN], ans[MAXN];

    i64 C(i64 x, i64 y)
    {
        if (x < y)
        {
            return 0;
        }
        return x * (x - 1) * (x - 2) * (x - 3) / 24;
    }

    void init()
    {
        for (int i = 0; i <= N; i++)
        {
            sum[i] = 0, ans[i] = 0;
        }
    }

    int main()
    {
        while (std::scanf("%d", &n) != EOF)
        {
            init();
            readAll(a + 1, a + n + 1);

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j * j <= a[i]; j++)
                {
                    if (a[i] % j == 0)
                    {
                        sum[j]++, j * j != a[i] && sum[a[i] / j]++;
                    }
                }
            }

            for (int i = N; i >= 1; i--)
            {
                ans[i] = C(sum[i], 4);
                for (int j = 2; i * j <= N; j++)
                {
                    ans[i] -= ans[i * j];
                }
            }

            write(ans[1]);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}