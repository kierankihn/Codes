#include <bits/stdc++.h>
namespace IO
{
    namespace basic_IO
    {
        template <typename T>
        void __read(T &x)
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
        template <typename First, typename... Rest>
        void __read(First &first, Rest &...rest)
        {
            __read(first);
            __read(rest...);
        }
        template <typename T>
        void __write(T x)
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
            basic_IO::__write(*i);
        }
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;

    const int MAXN = 1e5 + 5;
    const int MAXP = 5e6 + 5;

    int n;
    int ans = 0;
    int a[MAXN];

    struct Edge
    {
        int from, to, len;
    };
    std::vector<Edge> edge[MAXN];

    void dfs(int u, int fa)
    {
        for (auto &e : edge[u])
        {
            if (e.to == fa)
            {
                continue;
            }
            a[e.to] = a[u] ^ e.len, dfs(e.to, u);
        }
    }

    int cnt = 1;
    int son[MAXP][2];
    void add(int x)
    {
        auto u = 1;
        for (int i = 31; i >= 1; i--)
        {
            auto &v = son[u][(x >> (i - 1)) & 1];
            if (v == 0)
            {
                v = ++cnt;
            }
            u = v;
        }
    }
    int query(int x)
    {
        auto u = 1, res = 0;
        for (int i = 31; i >= 1; i--)
        {
            auto v = son[u][((x >> (i - 1)) & 1) ^ 1];
            if (v != 0)
            {
                res += 1 << (i - 1);
                u = v;
            }
            else
            {
                u = son[u][(x >> (i - 1)) & 1];
            }
        }
        return res;
    }

    int main()
    {
        read(n);
        for (int i = 1; i < n; i++)
        {
            int u, v, w;
            read(u, v, w);
            edge[u].push_back({u, v, w}), edge[v].push_back({v, u, w});
        }

        dfs(1, 0);

        for (int i = 1; i <= n; i++)
        {
            add(a[i]), ans = std::max(ans, query(a[i]));
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