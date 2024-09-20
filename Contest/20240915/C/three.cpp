/**
 * @author Kieran Kihn
 * @date 2024.09.15
 * @name three
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

    constexpr int MAXN = 5e3 + 5;
    constexpr int MOD  = 1e9 + 7;

    int n, m;
    int a[MAXN], sum[MAXN];

    std::vector<std::vector<std::vector<int>>> f;

    int &dp(int x, int y, int z)
    {
        if (x >= f.size())
        {
            f.resize(x + 5);
        }
        if (y >= f[x].size())
        {
            f[x].resize(y + 5);
        }
        if (z >= f[x][y].size())
        {
            f[x][y].resize(z + 5);
        }

        return f[x][y][z];
    }

    int main()
    {
        freopen("three.in", "r", stdin);
        freopen("three.out", "w", stdout);

        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            sum[a[i] = readi()]++;
        }

        dp(0, 0, 0) = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = sum[i]; j >= 0; j--)
            {
                for (int k = 0; k <= j; k++)
                {
                    int res     = dp(i, j + 3, k) + dp(i - 1, k + sum[i] - j, sum[i] - j);
                    dp(i, j, k) = res >= MOD ? res - MOD : res;
                }
            }
        }

        write(dp(m, 0, 0));

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}