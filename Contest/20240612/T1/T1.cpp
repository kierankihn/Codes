/**
 * @author Kieran Kihn
 * @date 2024.06.12
 * @name P5431 【模板】模意义下的乘法逆元 2
 * @link https://www.luogu.com.cn/problem/P5431
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

    constexpr int MAXN = 5e6 + 5;

    i64 qpow(i64 a, i64 b, i64 c)
    {
        i64 res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a % c;
            }
            a = a * a % c, b >>= 1;
        }
        return res;
    }

    int n, p, k;

    int a[MAXN];

    int b[MAXN], c[MAXN], inv[MAXN];

    int mul = 1;

    int ans = 0;

    int main()
    {
        read(n, p, k);
        readAll(a + 1, a + n + 1);

        b[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            b[i] = (i64)b[i - 1] * a[i] % p;
        }

        c[n] = qpow(b[n], p - 2, p);
        for (int i = n - 1; i >= 1; i--)
        {
            c[i] = (i64)c[i + 1] * a[i + 1] % p;
        }

        for (int i = 1; i <= n; i++)
        {
            inv[i] = (i64)c[i] * b[i - 1] % p;
        }

        for (int i = 1; i <= n; i++)
        {
            mul = (i64)mul * k % p;
            ans = ((i64)mul * inv[i] + ans) % p;
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