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

    constexpr int MOD  = 998244353;
    constexpr int MAXN = 3e7 + 5;

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

    i64 n, m, k;

    i64 ans = 0;

    int prime[MAXN], f[MAXN], g[MAXN];
    void init()
    {
        f[0] = g[0] = 0, f[1] = g[1] = 1;
        for (int i = 2; i <= k; i++)
        {
            if (f[i] == 0 || g[i] == 0)
            {
                f[i] = qpow(i, m), g[i] = qpow(i, n), prime[++prime[0]] = i;
            }
            for (int j = 1; j <= prime[0] && i * prime[j] <= k; j++)
            {
                f[i * prime[j]] = 1LL * f[i] * f[prime[j]] % MOD, g[i * prime[j]] = 1LL * g[i] * g[prime[j]] % MOD;
                if (i % prime[j] == 0)
                {
                    break;
                }
            }
        }
    }

    int main()
    {
        // freopen("matrix.in", "r", stdin);
        // freopen("matrix.out", "w", stdout);

        read(n, m, k);

        if (n == 1 || m == 1)
        {
            write(qpow(k, n * m));

            return 0;
        }

        init();

        for (int i = 1; i <= k; i++)
        {
            ans += 1LL * (f[i] - f[i - 1] + MOD) * g[k - i + 1] % MOD, ans %= MOD;
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