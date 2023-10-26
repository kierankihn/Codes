#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e5 + 5;
    const int INF = 0x3f3f3f3f;
    int t;
    int n;
    int ans = 0;
    struct Edge
    {
        int from, to, cap;
        Edge(int _from, int _to, int _cap) : from(_from), to(_to), cap(_cap) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXN];
    void insert(int u, int v, int c)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, c));
    }
    int d[MAXN], dp[MAXN];
    int dfs(int u, int fa)
    {
        for (auto &i : g[u])
        {
            auto &e = edge[i];
            if (e.to == fa)
            {
                continue;
            }
            d[u] += std::min(dfs(e.to, u) == 0 ? INF : d[e.to], e.cap);
        }
        return d[u];
    }
    void solve(int u, int fa)
    {
        ans = std::max(ans, dp[u]);
        for (auto &i : g[u])
        {
            auto &e = edge[i];
            if (e.to == fa)
            {
                continue;
            }
            dp[e.to] = d[e.to] + std::min(e.cap, dp[u] - std::min((d[e.to] == 0 ? INF : d[e.to]), e.cap));
            solve(e.to, u);
        }
    }
    void init()
    {
        ans = 0;
        edge.clear();
        for (int u = 1; u <= n; u++)
        {
            dp[u] = d[u] = 0, g[u].clear();
        }
    }
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            init();
            scanf("%d", &n);
            for (int i = 1; i < n; i++)
            {
                int u, v, c;
                scanf("%d %d %d", &u, &v, &c);
                insert(u, v, c), insert(v, u, c);
            }
            dp[1] = dfs(1, 0), solve(1, 0);
            printf("%d\n", ans);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}