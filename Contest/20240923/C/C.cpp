/**
 * @author Kieran Kihn
 * @date 2024.09.23
 * @name C
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
    } // namespace basic_IO
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
} // namespace IO
namespace solution
{
    using namespace IO;
    typedef double dbi;
    typedef long long i64;

    constexpr int MAXN = 1e3 + 5;

    struct Point
    {
        dbi x, y;
    };

    int n, m, q;
    int v[MAXN];
    Point a[MAXN], b[MAXN], c[MAXN];

    int pnpoly(int nvert, Point *vert, Point test)
    {
        int i, j, c = 0;
        for (i = 0, j = nvert - 1; i < nvert; j = i++)
        {
            if (((vert[i].y > test.y) != (vert[j].y > test.y)) &&
                (test.x < (vert[j].x - vert[i].x) * (test.y - vert[i].y) / (vert[j].y - vert[i].y) + vert[i].x))
            {
                c = !c;
            }
        }
        return c;
    }

    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            b[i].x = readi(), b[i].y = readi();
        }
        for (int i = 1; i <= m; i++)
        {
            a[i].x = readi(), a[i].y = readi(), v[i] = readi();
        }

        read(q);
        for (int i = 1; i <= q; i++)
        {
            int s = readi();
            std::vector<int> x;
            for (int j = 0; j < s; j++)
            {
                c[j] = b[readi()];
            }

            int res = 0;
            for (int i = 1; i <= m; i++)
            {
                res += pnpoly(s, c, a[i]) ? v[i] : 0;
            }

            write(res);
        }

        return 0;
    }
} // namespace solution
int main()
{
    solution::main();
    return 0;
}