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
    const int MAXN = 16000 + 5;
    const int INF = 0x3f3f3f3f;
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
    int n;
    int ans = -INF;
    int fa[MAXN];
    int val[MAXN];
    int dp[MAXN];
    bool vis[MAXN];
    void dfs(int u)
    {
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (fa[u] != e.to)
            {
                fa[e.to] = u;
                dfs(e.to);
            }
        }
    }
    int solve(int u)
    {
        if (dp[u])
        {
            return dp[u];
        }
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (fa[u] != e.to)
            {
                dp[u] += std::max(0, solve(e.to));
            }
        }
        dp[u] += val[u];
        return dp[u];
    }
    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(val[i]);
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            read(u, v);
            addEdge(u, v), addEdge(v, u);
        }
        dfs(1);
        for (int i = 1; i <= n; i++)
        {
            ans = std::max(ans, solve(i));
        }
        write(ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}