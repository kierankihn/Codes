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
    const int MAXN = 1e5 + 5;
    const int INF = 0x3f3f3f3f;
    const int MOD = 1e9 + 7;
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
    bool vis[MAXN];
    int fa[MAXN];
    int val[MAXN];
    LL dp[MAXN][4];
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
    LL solve(int u, int color)
    {
        if (dp[u][color] != -1)
        {
            return dp[u][color];
        }
        if (val[u] != 0 && val[u] != color)
        {
            return dp[u][color] = 0;
        }
        dp[u][color] = 1;
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (fa[u] != e.to)
            {
                if (val[u] == 0 || val[u] == color)
                {
                    LL tmp = 0;
                    for (int j = 1; j <= 3; j++)
                    {
                        if (j != color)
                        {
                            tmp += solve(e.to, j);
                            tmp %= MOD;
                        }
                    }
                    dp[u][color] *= tmp;
                    dp[u][color] %= MOD;
                }
            }
        }
        return dp[u][color];
    }
    int main()
    {
        std::memset(dp, -1, sizeof(dp));
        read(n, k);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            read(u, v);
            addEdge(u, v), addEdge(v, u);
        }
        for (int i = 1; i <= k; i++)
        {
            int idx, color;
            read(idx, color);
            val[idx] = color;
        }
        dfs(1);
        write((solve(1, 1) + solve(1, 2) + solve(1, 3)) % MOD);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}