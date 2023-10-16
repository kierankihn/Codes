#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 200 + 5;
    const int INF = 0x3f3f3f3f;
    int n, m;
    int s, t;
    int ans = 0;
    struct Edge
    {
        int from, to, cap;
        Edge(int _from, int _to, int _cap) : from(_from), to(_to), cap(_cap) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXN];
    void addEdge(int u, int v, int c)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, c));
    }
    int d[MAXN], now[MAXN];
    bool build()
    {
        std::queue<int> q;
        std::memset(d, 0, sizeof(d));
        std::memset(now, 0, sizeof(now));
        q.push(s), d[s] = 1;
        while (q.empty() == false)
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
                    d[e.to] = d[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return false;
    }
    int dinic(int u, int flow)
    {
        if (u == t)
        {
            return flow;
        }
        int rest = flow;
        for (int i = now[u]; rest != 0 && i < g[u].size(); i++)
        {
            now[u] = i;
            Edge &e = edge[g[u][i]], &ee = edge[g[u][i] ^ 1];
            if (e.cap != 0 && d[e.to] == d[u] + 1)
            {
                int add = dinic(e.to, std::min(rest, e.cap));
                if (add == 0)
                {
                    d[e.to] = 0;
                }
                rest -= add, e.cap -= add, ee.cap += add;
            }
        }
        return flow - rest;
    }
    int main()
    {
        scanf("%d%d", &m, &n);
        s = 1, t = n;
        for (int i = 1; i <= m; i++)
        {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            addEdge(u, v, c), addEdge(v, u, 0);
        }
        while (build())
        {
            int flow = 0;
            while ((flow = dinic(s, INF)) != 0)
            {
                ans += flow;
            }
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