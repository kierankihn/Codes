/**
 * @author Kieran Kihn
 * @date 2024.07.31
 * @name DEBUG
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
    constexpr int MOD  = 998244353;

    i64 qpow(i64 a, i64 b = MOD - 2, i64 c = MOD)
    {
        i64 res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a % c;
            }
            a = a * a % c, b = b >> 1;
        }
        return res;
    }

    int n, m;

    i64 ans = 0;

    i64 fac[MAXN], inv[MAXN];
    void init()
    {
        n = 1e6, fac[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fac[i] = fac[i - 1] * i % MOD;
        }
        inv[n] = qpow(fac[n]);
        for (int i = n - 1; i >= 0; i--)
        {
            inv[i] = inv[i + 1] * (i + 1) % MOD;
        }
    }
    i64 C(i64 x, i64 y)
    {
        return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
    }

    i64 calc(i64 x)
    {
        i64 res = 1;
        for (int i = 2; i * i <= x; i++)
        {
            i64 cnt = 0;
            while (x % i == 0)
            {
                cnt++, x /= i;
            }
            res = res * C(cnt + n - 1, n - 1) % MOD;
        }
        if (x != 1)
        {
            res = res * n % MOD;
        }
        return res;
    }

    int main()
    {
        init();

        read(n, m);
        for (int i = 1; i <= m; i++)
        {
            ans += calc(i), ans %= MOD;
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