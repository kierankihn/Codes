/**
 * @author Kieran Kihn
 * @date 2024.06.21
 * @name https://www.luogu.com.cn/problem/CF1942E
 * @link CF1942E
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
    constexpr int MOD  = 998244353;

    int t;

    i64 n, m;
    i64 ans = 0;

    i64 mul[MAXN * 2], inv[MAXN * 2];

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
    void init()
    {
        mul[0] = inv[0] = 1;
        for (int i = 1; i <= 2e6; i++)
        {
            mul[i] = mul[i - 1] * i % MOD;
            inv[i] = qpow(mul[i], MOD - 2, MOD);
        }
    }
    i64 C(i64 x, i64 y)
    {
        return mul[x] * inv[y] % MOD * inv[x - y] % MOD;
    }

    int main()
    {
        init();

        read(t);
        while (t--)
        {
            read(m, n), ans = 0;

            for (int i = 0; i + n * 2 <= m; i += 2)
            {
                ans += C(i / 2 + n - 1, n - 1) * C(m - (i + n * 2) + n + 1 - 1, n + 1 - 1) % MOD, ans %= MOD;
            }

            write((C(m, 2 * n) - ans + MOD) % MOD * 2 % MOD);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}