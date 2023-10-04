#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e6 + 5;
    const int INF = 0x3f3f3f3f;
    int n, s;
    int p;
    int ans = INF;
    int fa[MAXN];
    int dep[MAXN];
    bool mark[MAXN];
    struct Edge
    {
        int from, to, dis;
        Edge(int _from, int _to, int _dis) : from(_from), to(_to), dis(_dis) {}
    };
    std::vector<int> g[MAXN];
    std::vector<Edge> edge;
    void addEdge(int u, int v, int d)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, d));
    }
    void dfs(int u, int father)
    {
        fa[u] = father;
        if (dep[u] >= dep[p])
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
            if (mark[e.to])
            {
                continue;
            }
            dep[e.to] = dep[u] + e.dis;
            dfs(e.to, u);
        }
    }
    int main()
    {
        scanf("%d%d", &n, &s);
        for (int i = 1; i < n; i++)
        {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            addEdge(u, v, d), addEdge(v, u, d);
        }
        dfs(1, 0);
        dep[p] = 0;
        dfs(p, 0);
        for (int i = p, j = p; i != 0; i = fa[i])
        {
            while (dep[j] - dep[i] > s)
            {
                j = fa[j];
            }
            ans = std::min(ans, std::max(dep[p] - dep[j], dep[i]));
            mark[i] = true;
        }
        for (int i = p; i != 0; i = fa[i])
        {
            p = i, dep[i] = 0;
            dfs(i, fa[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            ans = std::max(ans, dep[i]);
        }
        printf("%d\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}