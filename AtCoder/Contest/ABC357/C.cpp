/**
 * @author Kieran Kihn
 * @date 2024.06.08
 * @name A
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

    constexpr int MAXN = 1e3 + 5;

    int n;

    char s[MAXN][MAXN];

    i64 qpow(i64 a, i64 b)
    {
        i64 res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a;
            }
            a = a * a, b = b >> 1;
        }
        return res;
    }

    void solve(int x, int a, int b)
    {
        if (x == 0)
        {
            s[a][b] = '#';
            return;
        }

        int len = qpow(3, x - 1);

        for (int i = a + len; i < a + len + len; i++)
        {
            for (int j = b + len; j < b + len + len; j++)
            {
                s[i][j] = '.';
            }
        }

        solve(x - 1, a, b);
        solve(x - 1, a, b + len);
        solve(x - 1, a, b + len + len);
        solve(x - 1, a + len, b);
        solve(x - 1, a + len, b + len + len);
        solve(x - 1, a + len + len, b);
        solve(x - 1, a + len + len, b + len);
        solve(x - 1, a + len + len, b + len + len);
    }

    int main()
    {
        read(n);

        solve(n, 0, 0);

        n = qpow(3, n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                putchar(s[i][j]);
            }
            putchar('\n');
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}