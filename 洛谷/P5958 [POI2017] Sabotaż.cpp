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
    const int MAXN = 5e5 + 5;
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
    int n, k;
    double ans = 0;
    int sz[MAXN];
    double dp[MAXN];
    void dfs(int u)
    {
        sz[u] = 1;
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            dfs(e.to);
            sz[u] += sz[e.to];
        }
    }
    double solve(int u)
    {
        if (dp[u] != 0)
        {
            return dp[u];
        }
        if (sz[u] == 1)
        {
            dp[u] = 1;
        }
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            dp[u] = std::max(dp[u], std::min(solve(e.to), (double)sz[e.to] / (sz[u] - 1)));
        }
        return dp[u];
    }
    int main()
    {
        std::cout.setf(std::ios::fixed);
        std::cout.precision(8);
        read(n, k);
        for (int i = 2; i <= n; i++)
        {
            int v;
            read(v);
            addEdge(v, i);
        }
        dfs(1);
        for (int i = 1; i <= n; i++)
        {
            if (sz[i] > k)
            {
                ans = std::max(ans, solve(i));
            }
        }
        std::cout << ans << std::endl;
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}