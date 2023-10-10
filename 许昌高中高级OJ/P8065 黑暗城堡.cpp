#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1000 + 5;
    const LL MOD = (1LL << 31LL) - 1;
    int n, m;
    LL ans = 1;
    bool inq[MAXN];
    int dist[MAXN];
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
    std::priority_queue<std::pair<int, int>> q;
    void push(int u)
    {
        if (inq[u] == false)
        {
            inq[u] = true;
            q.push(std::make_pair(dist[u], u));
        }
    }
    std::pair<int, int> pop()
    {
        auto p = q.top();
        q.pop();
        inq[p.second] = false;
        return p;
    }
    int main()
    {
        std::memset(dist, 0x3f, sizeof(dist));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            addEdge(u, v, d), addEdge(v, u, d);
        }
        dist[1] = 0, push(1);
        while (!q.empty())
        {
            auto now = pop();
            auto u = now.second;
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                if (dist[u] + e.dis < dist[e.to])
                {
                    dist[e.to] = dist[u] + e.dis;
                    push(e.to);
                }
            }
        }
        for (int u = 2; u <= n; u++)
        {
            int res = 0;
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                if (dist[u] == dist[e.to] + e.dis)
                {
                    res++;
                }
            }
            ans = ans * res % MOD;
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