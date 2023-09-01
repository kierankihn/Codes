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
    const int MAXN = 200000 + 5;
    const int MAXLOGN = 20;
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
    int root = 1;
    int dep[MAXN];
    int maxdep[MAXN];
    int fa[MAXN][MAXLOGN];
    int f[MAXN][MAXLOGN], h[MAXN][MAXLOGN];
    void dfs(int u, int father)
    {
        fa[u][0] = father, dep[u] = dep[father] + 1, maxdep[u] = dep[u], f[u][0] = 1;
        for (int i = 1; i <= std::log2(dep[u] - 1); i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
            f[u][i] = std::max(f[u][i - 1], f[fa[u][i - 1]][i - 1] + (1 << (i - 1)));
            h[u][i] = std::max(h[fa[u][i - 1]][i - 1], h[u][i - 1] + (1 << (i - 1)));
        }
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (e.to != father)
            {
                dfs(e.to, u);
                maxdep[u] = std::max(maxdep[u], maxdep[e.to]);
            }
        }
    }
    int solve(int u, int y)
    {
        int cnt = 0, res = 0;
        for (int i = std::log2(y); i >= 0 && cnt < y; i--)
        {
            if (cnt + (1 << i) < y)
            {
                cnt += (1 << i);
                u = fa[u][i];
                res = std::max(res, f[u][(int)std::log2(y - cnt)] + cnt);
            }
        }
        return res;
    }
    int main()
    {
        // freopen("pass.in", "r", stdin);
        // freopen("pass.out", "w", stdout);
        read(n);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            read(u, v);
            addEdge(u, v), addEdge(v, u);
        }
        dfs(1, 0);
        read(m);
        write(f[4][1]);
        for (int i = 1; i <= m; i++)
        {
            char op;
            std::cin >> op;
            if (op == 'C')
            {
                read(root);
            }
            if (op == 'Q')
            {
                int x, y, res = 0;
                read(x, y);
                res = std::max(res, maxdep[x]);
                res = std::max(res, solve(x, y));
                write(res, solve(x, y));
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}