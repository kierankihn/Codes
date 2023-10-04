#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    int n, k;
    int ans = 0;
    int s, t;
    int len = 0, root = 0;
    int dp[MAXN];
    bool link[MAXN];
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
    void dfs(int u, int father, int dep)
    {
        if (dep >= len)
        {
            len = dep, root = u;
        }
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (e.to == father)
            {
                continue;
            }
            dfs(e.to, u, dep + 1);
        }
    }
    bool record(int u, int father, int target)
    {
        if (u == target)
        {
            link[u] = true;
            return true;
        }
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (e.to == father)
            {
                continue;
            }
            if (record(e.to, u, target))
            {
                link[u] = true;
                return true;
            }
        }
        return false;
    }
    void solve(int u, int father)
    {
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (e.to == father)
            {
                continue;
            }
            solve(e.to, u);
            ans = std::max(ans, dp[u] + dp[e.to] + e.dis);
            dp[u] = std::max(dp[u], dp[e.to] + e.dis);
        }
    }
    int main()
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v, 1), addEdge(v, u, 1);
        }
        dfs(1, 0, 0);
        s = root, len = 0;
        dfs(root, 0, 0);
        t = root;
        if (k == 1)
        {
            printf("%d\n", 2 * (n - 1) - len + 1);
        }
        else
        {
            record(s, 0, t);
            for (auto &e : edge)
            {
                if (link[e.from] && link[e.to])
                {
                    e.dis = -1;
                }
            }
            solve(1, 0);
            printf("%d\n", 2 * (n - 1) - len - ans + 2);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}