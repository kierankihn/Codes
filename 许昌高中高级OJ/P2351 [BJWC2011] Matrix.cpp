#include <bits/stdc++.h>
namespace IO
{
    namespace basic_IO
    {
        template <typename T>
        void __read(T &x)
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
        template <typename First, typename... Rest>
        void __read(First &first, Rest &...rest)
        {
            __read(first);
            __read(rest...);
        }
        template <typename T>
        void __write(T x)
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
            basic_IO::__write(*i);
        }
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;

    const int MAXN = 1e3 + 5;
    const int BASE = 1e9 + 5;
    const int MOD  = 1e9 + 7;

    int n, m, a, b, q;
    int m1[MAXN][MAXN], m2[MAXN][MAXN];
    i64 p[MAXN * MAXN], hash[MAXN][MAXN];

    std::set<i64> s;

    void readMatrix(int ma[MAXN][MAXN], int x, int y)
    {
        char str[MAXN];
        for (int i = 1; i <= x; i++)
        {
            scanf("%s", str + 1);
            for (int j = 1; j <= y; j++)
            {
                ma[i][j] = str[j] - '0';
            }
        }
    }

    i64 calc(int x[MAXN][MAXN])
    {
        i64 res = 0;
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                res = res * BASE + x[i][j], res %= MOD;
            }
        }
        return res;
    }

    void init()
    {
        p[0] = 1;
        for (int i = 1; i <= 1e6; i++)
        {
            p[i] = p[i - 1] * BASE % MOD;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                hash[i][j] = hash[i][j - 1] * BASE + m1[i][j], hash[i][j] %= MOD;
            }
        }

        for (int j = 1; j <= m; j++)
        {
            i64 now = 0;
            for (int i = 1; i <= n; i++)
            {
                now = now * p[b] % MOD + (hash[i][j + b - 1] - hash[i][j - 1] * p[b] % MOD) % MOD, now %= MOD, now += MOD, now %= MOD;
                if (i > a)
                {
                    now -= (hash[i - a][j + b - 1] - hash[i - a][j - 1] * p[b]) % MOD * p[a * b] % MOD, now %= MOD, now += MOD, now %= MOD;
                }
                if (i >= a)
                {
                    // write(i - a + 1, j, now);
                    s.insert(now);
                }
            }
        }
    }

    int main()
    {
        read(n, m, a, b);
        readMatrix(m1, n, m);

        init();

        read(q);

        for (int i = 1; i <= q; i++)
        {
            readMatrix(m2, a, b);
            // write(calc(m2));
            if (s.count(calc(m2)))
            {
                write(1);
            }
            else
            {
                write(0);
            }
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}