/**
 * @author Kieran Kihn
 * @date 2024.07.01
 * @name P5505 [JSOI2011] 分特产
 * @link https://www.luogu.com.cn/problem/P5505
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

    constexpr int MAXN = 1e3 + 5;
    constexpr int MOD  = 1e9 + 7;

    i64 qpow(i64 a, i64 b, i64 c = MOD)
    {
        i64 res = 1;
        while (b)
        {
            if (b & 1)
            {
                res *= a, res %= c;
            }
            a *= a, a %= c, b >>= 1;
        }
        return res;
    }

    i64 n, m;

    i64 a[MAXN];

    i64 ans;

    i64 fac[MAXN * 2], inv[MAXN * 2];
    void init()
    {
        fac[0] = 1;
        for (int i = 1; i <= 2000; i++)
        {
            fac[i] = fac[i - 1] * i % MOD;
        }
        inv[2000] = qpow(fac[2000], MOD - 2);
        for (int i = 2000 - 1; i >= 0; i--)
        {
            inv[i] = inv[i + 1] * (i + 1) % MOD;
        }
    }

    i64 C(i64 x, i64 y)
    {
        return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
    }

    int main()
    {
        init();

        read(n, m);
        for (int i = 1; i <= m; i++)
        {
            read(a[i]);
        }

        for (int i = 0; i < n; i++)
        {
            i64 res = (C(n, i) * (i & 1 ? -1 : 1) + MOD) % MOD;
            for (int j = 1; j <= m; j++)
            {
                res = res * C(a[j] + (n - i) - 1, (n - i) - 1) % MOD;
            }
            ans += res, ans %= MOD;
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