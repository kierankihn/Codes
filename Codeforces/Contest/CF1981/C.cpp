/**
 * @author Kieran Kihn
 * @date 2024.05.29
 * @name CF1981C
 * @link https://codeforces.com/contest/1981/problem/C
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
    int a[MAXN], b[MAXN];

    std::vector<int> p;

    int dep(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        return std::__lg(x) + 1;
    }
    int fa(int x, int y)
    {
        return x / (1 << (y + 1));
    }

    int LCA(int x, int y)
    {
        if (dep(x) < dep(y))
        {
            std::swap(x, y);
        }
        while (dep(x) > dep(y))
        {
            x = fa(x, std::__lg(dep(x) - dep(y)));
        }
        if (x == y)
        {
            return x;
        }

        for (int i = 30; i >= 0; i--)
        {
            if (fa(x, i) != fa(y, i))
            {
                x = fa(x, i), y = fa(y, i);
            }
        }

        return fa(x, 0);
    }

    int main()
    {
        read(t);
        while (t--)
        {
            read(n), readAll(a + 1, a + n + 1);

            p.clear(), std::fill(b, b + n + 1, 0);

            for (int i = 1; i <= n; i++)
            {
                if (a[i] != -1)
                {
                    b[i] = a[i], p.push_back(i);
                }
            }

            if (p.empty())
            {
                for (int i = 1; i <= n; i++)
                {
                    b[i] = i & 1 ? 1 : 2;
                }
            }
            else
            {
                for (int i = p.front() - 1; i >= 1; i--)
                {
                    b[i] = ((i & 1) == (p.front() & 1)) ? b[i + 1] / 2 : b[i + 1] * 2;
                }
                for (int i = p.back() + 1; i <= n; i++)
                {
                    b[i] = ((i & 1) == (p.back() & 1)) ? b[i - 1] / 2 : b[i - 1] * 2;
                }
                for (std::size_t l = 1; l != p.size(); l++)
                {
                    int prev = p[l - 1], next = p[l];

                    int lca = LCA(a[prev], a[next]);

                    int prevlen = dep(a[prev]) - dep(lca);
                    int nextlen = dep(a[next]) - dep(lca);

                    if (prevlen + nextlen > next - prev ||
                        ((prevlen + nextlen) & 1) != ((next - prev) & 1))
                    {
                        b[0] = -1;
                        break;
                    }

                    int pos = prev + 1;
                    for (int j = 1; j <= prevlen; j++, pos++)
                    {
                        b[pos] = b[pos - 1] / 2;
                    }
                    for (int j = 1; j <= nextlen; j++, pos++)
                    {
                        b[pos] = b[pos - 1] * 2 | ((a[next] >> (nextlen - j)) & 1);
                    }
                    for (; pos < next; pos++)
                    {
                        b[pos] = ((pos & 1) == (next & 1)) ? b[pos - 1] / 2 : b[pos - 1] * 2;
                    }
                }
            }

            if (b[0] == -1)
            {
                write(-1);
            }
            else
            {
                writeAll(b + 1, b + n + 1);
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