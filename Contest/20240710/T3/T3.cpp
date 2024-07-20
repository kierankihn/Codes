/**
 * @author Kieran Kihn
 * @date 2024.07.10
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
    typedef char chr;
    typedef long long i64;

    constexpr int MAXN = 5e5 + 5;
    constexpr int MOD  = 998244353;

    i64 qpow(i64 a, i64 b = MOD - 2, i64 c = MOD)
    {
        if (b < 0)
        {
            return 0;
        }

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

    int t, id;

    int n;

    chr s[MAXN];
    i64 a[MAXN];

    i64 dp[MAXN];

    i64 cnt = 0, sum[10];

    i64 calc()
    {
        i64 ans = 0;

        cnt = 0;
        for (int i = 0; i < 10; i++)
        {
            sum[i] = 0;
        }

        for (i64 i = 2, i10 = 1; i <= n; i++)
        {
            dp[i] = 10 * dp[i - 1] % MOD + 45 * (i - 1) * i10 % MOD, i10 = i10 * 10 % MOD, dp[i] %= MOD;
        }
        for (int i = 1; i <= n; i++)
        {
            i64 i101 = qpow(10, n - i), i102 = qpow(10, n - i - 1);

            ans += cnt * a[i] % MOD * i101 % MOD, ans %= MOD;

            for (i64 j = 1; j < 10; j++)
            {
                ans += sum[j] * std::min(a[i], j) % MOD * i101 % MOD, ans %= MOD;
            }

            for (int j = 1; j < 10; j++)
            {
                ans += a[i] * sum[j] * j * (n - i) % MOD * i102 % MOD, ans %= MOD;
            }

            for (int j = 1; j < a[i]; j++)
            {
                ans += j * (n - i) * i102 % MOD, ans %= MOD;
            }

            ans += a[i] * dp[n - i] % MOD, ans %= MOD;

            sum[a[i]]++;
            for (int j = a[i] + 1; j < 10; j++)
            {
                cnt += sum[j], cnt %= MOD;
            }
        }

        ans += cnt, ans %= MOD;

        return ans;
    }
    i64 solve(bool flag)
    {
        read(s), n = std::strlen(s);
        for (int i = 0; i < n; i++)
        {
            a[i + 1] = s[i] - '0';
        }
        if (flag)
        {
            for (int i = n; i >= 1; i--)
            {
                if (a[i] == 0)
                {
                    a[i] = 9;
                }
                else
                {
                    a[i]--;
                    break;
                }
            }
        }
        return calc();
    }

    int main()
    {
        read(t, id);
        while (t--)
        {
            i64 ansl = solve(true), ansr = solve(false);
            write((ansr - ansl + MOD) % MOD);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}