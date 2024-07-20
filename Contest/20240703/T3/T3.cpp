// LUOGU_RID: 163842192
/**
 * @author Kieran Kihn
 * @date 2024.07.03
 * @name T3
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

    constexpr int MAXN   = 20 + 5;
    constexpr int MAXFAC = 50 + 5;
    constexpr int MAXLCM = 2520 + 5;
    constexpr int MOD    = 2520;

    int t;

    int a[MAXN];

    i64 dp[MAXN][MAXFAC][MAXLCM];

    std::map<int, int> id;

    void init()
    {
        std::memset(dp, -1, sizeof(dp));
        for (int i = 1, cnt = 0; i <= MOD; i++)
        {
            if (MOD % i == 0)
            {
                id[i] = ++cnt;
            }
        }
    }

    i64 lcm(i64 x, i64 y)
    {
        if (x == 0 || y == 0)
        {
            return x | y;
        }
        return x / std::__gcd(x, y) * y;
    }

    i64 solve(i64 len, i64 fac, i64 mod, bool limit)
    {
        if (len == 0)
        {
            return mod % fac == 0;
        }
        if (limit == false && dp[len][id[fac]][mod] != -1)
        {
            return dp[len][id[fac]][mod];
        }
        i64 res = 0;
        for (int i = 0; i <= 9; i++)
        {
            if (limit == false || i <= a[len])
            {
                res += solve(len - 1, lcm(fac, i), (mod * 10 + i) % MOD, limit && i == a[len]);
            }
        }
        if (limit == false)
        {
            dp[len][id[fac]][mod] = res;
        }
        return res;
    }

    i64 calc(i64 x)
    {
        for (int i = 1; i <= 20; i++)
        {
            a[i] = x % 10, x /= 10;
        }
        return solve(20, 1, 0, 1);
    }

    int main()
    {
        init();

        read(t);
        while (t--)
        {
            i64 l = readi(), r = readi();
            write(calc(r) - calc(l - 1));
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}