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
    typedef __int128 LL;
    using input::read;
    using output::write;
    const int MAXN = 2e5 + 5;
    const int MAXK = 1e6 + 5;
    const int MAXLOGN = 20 + 5;
    int n, m, k;
    LL t0 = 0;
    LL ans = 0;
    int a[MAXK];
    struct Edge
    {
        int from, to;
        LL dis;
        Edge() {}
        Edge(int u, int v, LL d) : from(u), to(v), dis(d) {}
    };
    bool operator<(const Edge a, const Edge b)
    {
        return a.dis < b.dis;
    }
    std::vector<Edge> edge;
    std::vector<int> g[MAXN];
    void addEdge(int u, int v, LL d)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, d));
    }
    int fb[MAXN];
    Edge input[MAXN];
    int find(int x)
    {
        if (x == fb[x])
        {
            return x;
        }
        return fb[x] = find(fb[x]);
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        fb[y] = x;
    }
    int fa[MAXN][MAXLOGN];
    int dep[MAXN];
    LL dist[MAXN];
    void dfs(int u, int father)
    {
        fa[u][0] = father, dep[u] = dep[father] + 1;
        for (int i = 1; i <= std::log2(dep[u] - 1); i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (e.to == father)
            {
                continue;
            }
            dist[e.to] = dist[u] + e.dis;
            dfs(e.to, u);
        }
    }
    int LCA(int x, int y)
    {
        if (dep[x] < dep[y])
        {
            std::swap(x, y);
        }
        while (dep[x] > dep[y])
        {
            x = fa[x][(int)std::log2(dep[x] - dep[y])];
        }
        if (x == y)
        {
            return x;
        }
        for (int i = std::log2(dep[x]); i >= 0; i--)
        {
            if (fa[x][i] != fa[y][i])
            {
                x = fa[x][i], y = fa[y][i];
            }
        }
        return fa[x][0];
    }
    int main()
    {
        freopen("D.in", "r", stdin);
        freopen("D.out", "w", stdout);
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            fb[i] = i;
        }
        for (int i = 1; i <= m; i++)
        {
            read(input[i].from, input[i].to, input[i].dis);
        }
        read(k, t0);
        for (int i = 1; i <= k; i++)
        {
            read(a[i]);
        }
        std::sort(input + 1, input + m + 1);
        for (int i = 1; i <= m; i++)
        {
            Edge &e = input[i];
            if (find(e.from) != find(e.to))
            {
                merge(e.from, e.to);
                addEdge(e.from, e.to, e.dis), addEdge(e.to, e.from, e.dis);
            }
        }
        dfs(1, 0);
        for (int i = 2; i <= k; i++)
        {
            if (a[i] == a[i - 1])
            {
                continue;
            }
            int lca = LCA(a[i], a[i - 1]);
            ans += dist[a[i]] + dist[a[i - 1]] - 2 * dist[lca] + (dep[a[i]] + dep[a[i - 1]] - 2 * dep[lca]) * t0;
        }
        ans -= t0;
        write(ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}