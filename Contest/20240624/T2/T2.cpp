/**
 * @author Kieran Kihn
 * @date 2024.06.24
 * @name T2
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

    constexpr int MAXN = 3e5 + 5;

    int n, m, q;

    int color[MAXN];

    int max[MAXN];

    std::vector<int> e[MAXN];

    void dfs(int u, int father, int c)
    {
        color[u] = c;
        for (auto v : e[u])
        {
            if (v != father)
            {
                dfs(v, u, c);
            }
        }
    }
    int find(int x)
    {
        if (x != color[x])
        {
            return color[x] = find(color[x]);
        }

        return x;
    }

    int res = 0;
    int dep[MAXN];

    void dfsmax(int u, int father)
    {
        dep[u] = dep[father] + 1;
        if (dep[u] > dep[res])
        {
            res = u;
        }

        for (auto v : e[u])
        {
            if (v != father)
            {
                dfsmax(v, u);
            }
        }
    }

    int main()
    {
        read(n, m, q);
        for (int i = 1; i <= m; i++)
        {
            int u = readi(), v = readi();
            e[u].push_back(v), e[v].push_back(u);
        }

        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 0)
            {
                dfs(i, 0, i);

                dfsmax(i, res = 0), dfsmax(res, 0);
                max[i] = dep[res] - 1;
            }
        }
        for (int i = 1; i <= q; i++)
        {
            int op = readi();
            if (op == 1)
            {
                int x = find(readi());
                write(max[x]);
            }
            if (op == 2)
            {
                int x = find(readi()), y = find(readi());
                if (x != y)
                {
                    color[y] = x;
                    max[x]   = std::max({max[x], max[y], (max[x] + 1) / 2 + (max[y] + 1) / 2 + 1});
                }
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