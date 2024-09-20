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

    constexpr int MAXN = 100 + 5;

    constexpr int map1[MAXN][MAXN][MAXN] = {{{1, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{1, 1, 0}, {0, 0, 0}, {0, 0, 0}}};
    constexpr int map2[MAXN][MAXN][MAXN] = {{{1, 0, 1}, {1, 0, 0}, {0, 0, 0}}, {{1, 1, 0}, {0, 1, 0}, {0, 0, 0}}, {{1, 0, 0}, {1, 1, 1}, {0, 0, 0}}, {{1, 1, 0}, {0, 0, 0}, {1, 1, 0}}, {{1, 0, 1}, {1, 0, 0}, {0, 1, 1}}, {{1, 1, 0}, {0, 1, 1}, {0, 0, 0}}, {{1, 0, 0}, {1, 1, 1}, {0, 0, 1}}, {{1, 1, 0}, {0, 0, 0}, {1, 1, 0}}, {{1, 0, 1}, {1, 0, 0}, {0, 0, 1}}, {{1, 1, 0}, {0, 1, 0}, {0, 0, 0}}, {{1, 0, 0}, {1, 1, 1}, {0, 0, 0}}, {{1, 1, 0}, {0, 0, 0}, {1, 1, 1}}, {{1, 0, 1}, {1, 0, 0}, {0, 1, 0}}, {{1, 1, 0}, {0, 1, 1}, {0, 0, 1}}, {{1, 0, 0}, {1, 1, 1}, {0, 0, 0}}, {{1, 1, 0}, {0, 0, 0}, {1, 1, 1}}};

    i64 q;

    int main()
    {
        freopen("nothingness.in", "r", stdin);
        freopen("nothingness.out", "w", stdout);

        read(q);
        for (int i = 1; i <= q; i++)
        {
            i64 t = readi(), x = readi(), y = readi(), res = t <= 1 ? map1[t][x][y] : map2[(t - 2) % 16][x][y];

            if (res)
            {
                write("YES");
            }
            else
            {
                write("NO");
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