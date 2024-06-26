/**
 * @author Kieran Kihn
 * @date 2024.06.25
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

    constexpr int MAXN = 1e5 + 5;
    constexpr int MAXL = 100 + 5;

    int n;

    std::set<int> ans[MAXN];

    int a[MAXL][MAXL][MAXL], b[MAXL][MAXL][MAXL], c[MAXL][MAXL][MAXL];

    void update(int x, int y)
    {
        ans[x].insert(y), ans[y].insert(x);
    }
    void add(int v[MAXL][MAXL][MAXL], int id, int x, int y1, int y2, int z1, int z2)
    {
        for (int i = y1; i < y2; i++)
        {
            for (int j = z1; j < z2; j++)
            {
                if (v[x][i][j] != 0)
                {
                    update(id, v[x][i][j]);
                }
                v[x][i][j] = id;
            }
        }
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            int x1, x2, y1, y2, z1, z2;
            read(x1, y1, z1, x2, y2, z2);

            add(a, i, x1, y1, y2, z1, z2);
            add(a, i, x2, y1, y2, z1, z2);
            add(b, i, y1, x1, x2, z1, z2);
            add(b, i, y2, x1, x2, z1, z2);
            add(c, i, z1, x1, x2, y1, y2);
            add(c, i, z2, x1, x2, y1, y2);
        }

        for (int i = 1; i <= n; i++)
        {
            write(ans[i].size());
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}