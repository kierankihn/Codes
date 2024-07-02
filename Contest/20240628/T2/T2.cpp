/**
 * @author Kieran Kihn
 * @date 2024.06.28
 * @name T2
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

    constexpr int MAXN = 1e6 + 5;

    int t;

    i64 n;
    i64 a[MAXN], b[MAXN];

    i64 ans = 0;

    i64 g[MAXN], p[MAXN];

    void init()
    {
        ans = 0;
        std::fill(a + 1, a + n + 1, 0);
        std::fill(b + 1, b + n + 1, 0);
        std::fill(g + 1, g + n + 1, 0);
        std::fill(p + 1, p + n + 1, 0);
    }

    int main()
    {
        read(t);
        while (t--)
        {
            read(n), init();
            for (int i = 1; i <= n; i++)
            {
                b[a[i] = readi()]++;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; i * j <= n; j++)
                {
                    g[i * j] |= bool(b[i]);
                }
            }

            for (int i = n; i >= 1; i--)
            {
                for (int j = 1; i * j <= n; j++)
                {
                    p[i] += b[i * j];
                }
                p[i] = p[i] * (p[i] - 1) / 2;
                for (int j = 2; i * j <= n; j++)
                {
                    p[i] -= p[i * j];
                }

                ans += g[i] * p[i];
            }

            write(n * (n - 1) / 2 - ans);
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
 * 求 \sigma_{1 <= i <= n} \sigma_{i + 1 <= j <= n} g[gcd(a[i], a[j])]
 * g[i] 表示 [1, n] 中是否存在 a[j] 使得 a[j] | i
 * 枚举 gcd(a[i], a[j]) 的值
 * 考虑有多少对 (i, j) 使得 gcd(a[i], a[j]) = x，记这个对数为 p[i]
 * 答案即为 \sigma p[i] * g[i]
 */