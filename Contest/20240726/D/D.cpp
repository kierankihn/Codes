/**
 * @author Kieran Kihn
 * @date 2024.07.26
 * @name D
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

    constexpr int MAXN = 5e6 + 5;
    constexpr int MOD  = 1e9 + 7;

    int t, l, r;

    i64 ans = 0;
    i64 f[MAXN];

    int prime[MAXN], fac[MAXN];
    void init()
    {
        int n = 5e6;
        for (int i = 2; i <= 5e6; i++)
        {
            if (fac[i] == 0)
            {
                prime[++prime[0]] = i;
            }
            for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++)
            {
                fac[i * prime[j]] = prime[j];
                if (i % prime[j] == 0)
                {
                    break;
                }
            }
        }
    }

    int main()
    {
        init();

        read(t, l, r);
        for (i64 i = 2; i <= r; i++)
        {
            if (fac[i] == 0)
            {
                f[i] = i * (i - 1) / 2;
            }
            else
            {
                f[i] = f[i / fac[i]] + i / fac[i] * f[fac[i]];
            }
            f[i] %= MOD;
        }

        for (i64 i = l, mul = 1; i <= r; i++, mul = mul * t % MOD)
        {
            ans += f[i] * mul, ans %= MOD;
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