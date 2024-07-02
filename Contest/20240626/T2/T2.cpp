/**
 * @author Kieran Kihn
 * @date 2024.06.26
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

    constexpr int MAXN = 3e4 + 5;

    int n, m;

    int ans = 0;

    std::vector<int> e1[MAXN], e2[MAXN];

    std::bitset<MAXN> from[MAXN], to[MAXN];

    int a[MAXN];
    int du[MAXN];
    void topo()
    {
        std::queue<int> q;
        for (int u = 1; u <= n; u++)
        {
            for (auto v : e1[u])
            {
                du[v]++;
            }
        }
        for (int u = 1; u <= n; u++)
        {
            if (du[u] == 0)
            {
                q.push(u);
            }
        }

        while (q.empty() == false)
        {
            int u = q.front();
            q.pop(), a[++a[0]] = u;

            for (auto v : e1[u])
            {
                if (--du[v] == 0)
                {
                    q.push(v);
                }
            }
        }
    }

    int main()
    {
        read(n, m);
        for (int i = 1; i <= m; i++)
        {
            int u = readi(), v = readi();
            e1[u].push_back(v), e2[v].push_back(u);
        }

        topo();

        for (int i = 1; i <= n; i++)
        {
            int u = a[i];
            for (auto v : e1[u])
            {
                from[v][u] = 1, from[v] |= from[u];
            }
        }
        for (int i = n; i >= 1; i--)
        {
            int u = a[i];
            for (auto v : e2[u])
            {
                to[v][u] = 1, to[v] |= to[u];
            }
        }

        for (int u = 1; u <= n; u++)
        {
            for (auto v : e1[u])
            {
                ans += (to[u] & from[v]).any();
            }
        }

        write(ans);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}