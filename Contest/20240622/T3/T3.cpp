/**
 * @author Kieran Kihn
 * @date 2024.06.22
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

    constexpr int MAXN    = 2e6 + 5;
    constexpr int MAXLOGN = 20 + 5;

    int n, m;
    int a, b, len;

    int dep[MAXN], fa[MAXN][MAXLOGN];

    void init()
    {
        n = 4, a = 2, b = 3, len = 2;

        dep[1] = 1;
        dep[2] = 2, fa[2][0] = 1;
        dep[3] = 2, fa[3][0] = 1;
        dep[4] = 2, fa[4][0] = 1;
    }

    void get(int u, int father)
    {
        dep[u] = dep[father] + 1, fa[u][0] = father;
        for (int i = 1; i <= std::__lg(dep[u]); i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
    }

    int LCA(int x, int y)
    {
        if (dep[x] < dep[y])
        {
            std::swap(x, y);
        }
        while (dep[x] > dep[y])
        {
            x = fa[x][std::__lg(dep[x] - dep[y])];
        }
        if (x == y)
        {
            return x;
        }

        for (int i = std::__lg(dep[x]); i >= 0; i--)
        {
            if (fa[x][i] != fa[y][i])
            {
                x = fa[x][i], y = fa[y][i];
            }
        }

        return fa[x][0];
    }

    void update(int x, int y)
    {
        int lca = LCA(x, y);
        if (dep[x] + dep[y] - 2 * dep[lca] > len)
        {
            len = dep[x] + dep[y] - 2 * dep[lca];
            a = x, b = y;
        }
    }

    int main()
    {
        init();
        read(m);

        for (int i = 1; i <= m; i++)
        {
            int x = readi();
            get(++n, x), get(++n, x);

            update(n, a), update(n, b);

            write(len);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}