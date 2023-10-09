#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e5 + 5;
    int n;
    struct Edge
    {
        int from, to;
        LL dis;
        Edge(int _from, int _to, LL _dis) : from(_from), to(_to), dis(_dis) {}
    };
    std::vector<int> g[MAXN];
    std::vector<Edge> edge;
    void addEdge(int u, int v, LL d)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, d));
    }
    int p;
    int s;
    int ans = 0;
    int fa[MAXN];
    int son[MAXN];
    LL dis[MAXN];
    LL dep[MAXN];
    bool mark[MAXN];
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
        scanf("%d", &n);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            LL d;
            scanf("%d%d%lld", &u, &v, &d);
            addEdge(u, v, d), addEdge(v, u, d);
        }
        p = 0, dfs(1, 0);
        s = p, p = dep[s] = 0, dfs(s, 0);
        s = p;
        for (int i = s; i != 0; son[fa[i]] = i, i = fa[i])
        {
            mark[i] = true;
        }
        for (int i = s; i != 0; i = fa[i])
        {
            LL tmp = dep[i];
            p = 0, dep[i] = 0, dfs(i, fa[i]);
            dis[i] = dep[p], dep[i] = tmp;
        }
        int l = s, r = s;
        while (dep[l] != dis[l])
        {
            l = fa[l];
        }
        while (fa[r] != 0)
        {
            r = fa[r];
        }
        while (dep[s] - dep[r] != dis[r])
        {
            r = son[r];
        }
        while (l != r)
        {
            r = fa[r], ans++;
        }
        printf("%lld\n%d\n", dep[s], ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}