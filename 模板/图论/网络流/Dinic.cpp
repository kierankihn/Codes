#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 200 + 5;
    const LL INF = 0x3f3f3f3f3f3f3f3f;
    int n, m;
    int s, t;
    struct Edge
    {
        int from, to;
        LL cap;
        Edge(int _from, int _to, LL _cap) : from(_from), to(_to), cap(_cap) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXN];
    void addEdge(int u, int v, LL c)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, c));
    }
    int d[MAXN];
    int now[MAXN];
    bool build()
    {
        std::memset(d, 0, sizeof(d));
        std::memset(now, 0, sizeof(now));
        std::queue<int> q;
        q.push(s), d[s] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == t)
            {
                return true;
            }
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                if (e.cap != 0 && d[e.to] == 0)
                {
                    d[e.to] = d[u] + 1, q.push(e.to);
                }
            }
        }
        return false;
    }
    LL dinic(int u, LL flow)
    {
        if (u == t)
        {
            return flow;
        }
        LL rest = flow;
        for (int i = now[u]; i < g[u].size(); i++)
        {
            now[u] = i;
            Edge &e = edge[g[u][i]];
            if (e.cap != 0 && d[e.to] == d[u] + 1)
            {
                int add = dinic(e.to, std::min(rest, e.cap));
                if (add == 0)
                {
                    d[e.to] = 0;
                }
                rest -= add, edge[g[u][i]].cap -= add, edge[g[u][i] ^ 1].cap += add;
            }
        }
        return flow - rest;
    }
    int main()
    {
        scanf("%d%d", &n, &m);
        scanf("%d%d", &s, &t);
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            LL c;
            scanf("%d%d%lld", &u, &v, &c);
            addEdge(u, v, c), addEdge(v, u, 0);
        }
        LL flow = 0, ans = 0;
        while (build())
        {
            while ((flow = dinic(s, INF)) != 0)
            {
                ans += flow;
            }
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