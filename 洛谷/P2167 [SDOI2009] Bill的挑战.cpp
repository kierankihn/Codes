/**
 * @author Kieran Kihn
 * @date 2024.07.01
 * @name P2167 [SDOI2009] Bill的挑战
 * @link https://www.luogu.com.cn/problem/P2167
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

    constexpr int MAXN = 20 + 5;
    constexpr int MOD  = 1e6 + 3;

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

    int t;

    int n, k, l;

    std::string s[MAXN];

    i64 ans[MAXN];

    i64 calc(i64 x)
    {
        i64 res = 0;
        for (int i = 0; i < l; i++)
        {
            int now = 0;
            for (int j = 1; j <= n; j++)
            {
                if (x & (1 << (j - 1)))
                {
                    if (s[j][i] != '?')
                    {
                        if (now != 0 && now != s[j][i])
                        {
                            now = -1;
                            break;
                        }
                        now = s[j][i];
                    }
                }
            }
            if (now == 0)
            {
                res++;
            }
            if (now == -1)
            {
                return 0;
            }
        }
        return qpow(26, res);
    }

    i64 C(i64 x, i64 y)
    {
        i64 res = 1;
        for (int i = y + 1; i <= x; i++)
        {
            res *= i, res %= MOD;
        }
        for (int i = 1; i <= x - y; i++)
        {
            res *= qpow(i, MOD - 2), res %= MOD;
        }
        return res;
    }

    int main()
    {
        read(t);
        while (t--)
        {
            std::memset(ans, 0, sizeof(ans));

            read(n, k);
            readAll(s + 1, s + n + 1);
            l = s[1].size();

            for (int umask = 1; umask < (1 << n); umask++)
            {
                ans[__builtin_popcount(umask)] += calc(umask);
                ans[__builtin_popcount(umask)] %= MOD;
            }

            for (int i = k; i <= n; i++)
            {
                ans[0] += ((i - k) & 1 ? -1 : 1) * ans[i] * C(i, k) % MOD + MOD;
                ans[0] %= MOD;
            }

            write(ans[0]);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}