#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e5 + 5;
    const int MAXLOGN = 20 + 5;
    using std::printf;
    using std::scanf;
    struct Edge
    {
        int from, to;
        LL dis;
        Edge(int _from, int _to, LL _dis) : from(_from), to(_to), dis(_dis) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXN];
    void addEdge(int u, int v, LL d)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, d));
    }
    int n, m;
    LL ans = 0;
    int fa[MAXN][MAXLOGN];
    int dep[MAXN];
    void init(int u, int father)
    {
        fa[u][0] = father, dep[u] = dep[father] + 1;
        for (int i = 1; i <= std::log2(dep[u] - 1); i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (father == e.to)
            {
                continue;
            }
            init(e.to, u);
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
    int p;
    int l, r;
    LL len = 0;
    LL dis[MAXN];
    void dfs(int u, int father)
    {
        if (dis[u] > dis[p])
        {
            p = u;
        }
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (e.to == father)
            {
                continue;
            }
            dis[e.to] = dis[u] + e.dis;
            dfs(e.to, u);
        }
    }
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            addEdge(u, v, d), addEdge(v, u, d);
        }
        init(1, 0);
        dfs(1, 0);
        len = dis[p], l = p, p = 0, dis[l] = 0;
        dfs(l, 0);
        len = dis[p], r = p, p = 0, dis[1] = 0;
        dfs(1, 0);
        for (int i = 1; i <= n; i++)
        {
            ans = std::max(ans, std::min(dis[i] + dis[l] - 2 * dis[LCA(i, l)], dis[i] + dis[r] - 2 * dis[LCA(i, r)]) + len);
        }
        printf("%lld\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}