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

    constexpr int MAXN  = 9;
    constexpr int MAXP  = 5;
    constexpr int MAX2P = 17;
    constexpr int INF   = 0x3f3f3f3f;

    int t;

    int n;
    int a[MAXN][MAXN];

    int min1, min2;
    int dp[2][MAXN][MAX2P][MAX2P];

    int get(int x, int pos)
    {
        return (x >> (4 - pos)) & 1;
    }

    void input()
    {
        n = 7;
        for (int i = 1; i <= n; i++)
        {
            auto s = reads();

            for (int j = 1; j <= n; j++)
            {
                a[i][j] = s[j - 1] == 'B';
            }
        }
        n = 8;
    }

    int calc(int line, int x, int delta)
    {
        int res = 0;
        for (int i = 1; i <= 4; i++)
        {
            if (a[line][i * 2 - 1 + delta] != get(x, i))
            {
                res++;
            }
        }

        return res;
    }
    int check(int x, int y, int delta)  // x: 中间一行，y:上下两行 (0010,0011,1)
    {
        for (int i = 2 - delta; i <= 4 - delta; i++)
        {
            if (get(x, i) && get(y, i + delta) && get(y, i - 1 + delta))
            {
                return false;
            }
        }

        return true;
    }

    int main()
    {
        read(t);
        while (t--)
        {
            input();

            std::memset(dp, 0x3f, sizeof(dp));

            for (int o = 0; o <= 1; o++)
            {
                for (int i = 0; i < (1 << 4); i++)
                {
                    for (int j = 0; j < (1 << 4); j++)
                    {
                        dp[o][2][i][j] = calc(1, i, o) + calc(2, j, o ^ 1);
                    }
                }
            }

            for (int o = 0; o <= 1; o++)
            {
                for (int i = 3; i <= n; i++)
                {
                    int delta = (i & 1) ^ 1 ^ o;
                    for (int j = 0; j < (1 << 4); j++)
                    {
                        for (int k = 0; k < (1 << 4); k++)  // dp[o][i][j][k] <- dp[o][i - 1][p][j] (p, j, k)
                        {
                            for (int p = 0; p < (1 << 4); p++)
                            {
                                if (check(j, p & k, delta ^ 1))
                                {
                                    dp[o][i][j][k] = std::min(dp[o][i][j][k], dp[o][i - 1][p][j] + calc(i, k, delta));
                                }
                            }
                        }
                    }
                }
            }

            min1 = min2 = INF;
            for (int i = 0; i < (1 << 4); i++)
            {
                for (int j = 0; j < (1 << 4); j++)
                {
                    min1 = std::min(min1, dp[0][n][i][j]), min2 = std::min(min2, dp[1][n][i][j]);
                }
            }

            write(min1 + min2);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}