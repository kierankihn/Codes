/**
 * @author Kieran Kihn
 * @date 2024.07.23
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

    int t;

    int n;
    int d1, d2, last;

    int du[MAXN], vis[MAXN];

    std::set<int> e[MAXN];
    std::vector<std::pair<int, int>> add, del;

    void insert(int x)
    {
        if (last == 0)
        {
            last = x;
        }
        else
        {
            add.push_back({last, x});
            last = 0;
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
            for (int i = 1; i < n; i++)
            {
                int u = readi(), v = readi();
                du[u]++, du[v]++;
                e[u].insert(v), e[v].insert(u);
            }

            d1 = d2 = 0;
            for (int u = 1; u <= n; u++)
            {
                if (du[u] <= 1)
                {
                    if (du[u] == 0)
                    {
                        if (d1 == 0)
                        {
                            d1 = u, insert(u);
                        }
                        else if (d2 == 0)
                        {
                            d2 = u, insert(u);
                        }
                        else
                        {
                            insert(d1), insert(u), d1 = u;
                        }
                    }
                    else
                    {
                        if (d1 == 0)
                        {
                            d1 = u;
                        }
                        else if (d2 == 0)
                        {
                            d2 = u;
                        }
                        else
                        {
                            insert(u);
                        }
                    }
                }
                else
                {
                    for (auto v : e[u])
                    {
                        if (du[u] > 2 && du[v] > 2)
                        {
                            du[u]--, du[v]--;
                            del.push_back({u, v}), vis[v] = true;
                        }
                    }
                    for (auto v : e[u])
                    {
                        if (du[u] > 2 && vis[v] == false)
                        {
                            du[u]--, du[v]--;
                            del.push_back({u, v});
                        }
                    }
                }
            }

            write(add.size(), del.size());
            for (int i = 0; i < add.size() && i < del.size(); i++)
            {
                write(del[i].first, del[i].second, add[i].first, add[i].second);
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