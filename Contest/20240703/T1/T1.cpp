/**
 * @author Kieran Kihn
 * @date 2024.07.03
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

    constexpr int MAXN = 2000 + 5;

    int n;

    std::vector<int> e[MAXN];

    int dfn_tot = 0, scc_tot = 0;
    int dfn[MAXN], low[MAXN], scc[MAXN];

    int in_stack[MAXN];
    std::stack<int> s;
    void tarjan(int u)
    {
        dfn[u] = low[u] = ++dfn_tot, in_stack[u] = true, s.push(u);
        for (auto v : e[u])
        {
            if (dfn[v] != 0 && in_stack[v] == true)
            {
                low[u] = std::min(low[u], low[v]);
            }
            if (dfn[v] == 0)
            {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            }
        }
        if (low[u] == dfn[u])
        {
            scc_tot++;
            for (int now = 0; now != u;)
            {
                scc[now = s.top()] = scc_tot, s.pop(), in_stack[now] = false;
            }
        }
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (readi() != 0)
                {
                    e[i].push_back(j);
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (scc[i] == 0)
            {
                tarjan(i);
            }
        }

        if (scc_tot == 1)
        {
            write("YES");
        }
        else
        {
            write("NO");
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}