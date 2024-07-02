/**
 * @author Kieran Kihn
 * @date 2024.06.26
 * @name T1
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

    constexpr int MAXN = 2e5 + 5;

    int t;

    int n;
    int a[MAXN];

    std::set<int> e[MAXN];

    int cnt = 0;
    int color[MAXN], loop[MAXN];

    int min, max;

    void dfs(int u, int fa, int c)
    {
        color[u] = c;

        for (auto v : e[u])
        {
            if (v != fa)
            {
                if (color[v] == 0)
                {
                    dfs(v, u, c);
                }
                else
                {
                    loop[c] = true;
                }
            }
        }
    }

    int main()
    {
        read(t);
        while (t--)
        {
            read(n);
            for (int i = 1; i <= n; i++)
            {
                e[i].clear();
            }
            for (int i = 1; i <= n; i++)
            {
                read(a[i]);
                e[i].insert(a[i]), e[a[i]].insert(i);
            }

            min = 0, max = 0, cnt = 0;
            std::fill(loop + 1, loop + n + 1, 0);
            std::fill(color + 1, color + n + 1, 0);

            for (int i = 1; i <= n; i++)
            {
                if (color[i] == 0)
                {
                    dfs(i, 0, ++cnt);
                    if (loop[cnt])
                    {
                        min++, max++;
                    }
                    else
                    {
                        max++;
                    }
                }
            }
            for (int i = 1; i <= n; i++)
            {
                if (loop[color[i]] == 0)
                {
                    min++;
                    break;
                }
            }

            write(min, max);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}