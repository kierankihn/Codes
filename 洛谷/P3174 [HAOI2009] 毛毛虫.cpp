#include <bits/stdc++.h>
namespace input
{
    template <typename T>
    void read(T &x)
    {
        T res = 0, s = 1;
        char ch;
        while ((ch = getchar()) < '0' || ch > '9')
            if (ch == '-')
                s = -1;
        while (ch >= '0' && ch <= '9')
            res = res * 10 + ch - '0', ch = getchar();
        x = res * s;
    }
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        read(first);
        read(rest...);
    }
}
namespace output
{
    void write()
    {
        putchar('\n');
    }
    void write(char ch)
    {
        putchar(ch);
    }
    template <typename T>
    void write(char delimiter, T x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            write(delimiter, x / 10);
        putchar((x % 10) + '0');
    }
    template <typename First, typename... Rest>
    void write(char delimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
    }
    template <typename First, typename... Rest>
    void write(char delimiter, char linedelimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
        putchar(linedelimiter);
    }
    template <typename... T>
    void write(T... t)
    {
        write(' ', '\n', t...);
    }
}
namespace solution
{
    typedef long long LL;
    const int MAXN = 3e5 + 5;
    using input::read;
    using output::write;
    struct Edge
    {
        int from, to;
        Edge(int u, int v) : from(u), to(v) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXN];
    void addEdge(int u, int v)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v));
    }
    int n, m;
    int ans = 0;
    int f[MAXN];
    int solve(int u, int fa)
    {
        int max0 = 0, max1 = 0, cnt = g[u].size();
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (e.to == fa)
            {
                continue;
            }
            f[u] = std::max(f[u], solve(e.to, u));
            if (f[e.to] > max0)
            {
                max1 = max0;
                max0 = f[e.to];
            }
            else if (f[e.to] > max1)
            {
                max1 = f[e.to];
            }
        }
        f[u] += 1 + std::max(cnt - 1 - (fa != -1), 0);
        ans = std::max(ans, max0 + max1 + std::max(0, cnt - 2) + 1);
        return f[u];
    }
    int main()
    {
        read(n, m);
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            read(u, v);
            addEdge(u, v);
            addEdge(v, u);
        }
        solve(1, -1);
        write(ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}