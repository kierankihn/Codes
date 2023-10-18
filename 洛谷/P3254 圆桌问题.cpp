#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 300 + 5;
    const int MAXP = 1000 + 5;
    const int INF = 0x3f3f3f3f;
    int n, m;
    int s, t;
    int maxflow = 0;
    int r[MAXN], c[MAXN];
    std::vector<int> ans[MAXN];
    struct Edge
    {
        int from, to, cap;
        Edge(int _from, int _to, int _cap) : from(_from), to(_to), cap(_cap) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXP];
    void addEdge(int u, int v, int c)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, c));
    }
    void insert(int u, int v, int c)
    {
        addEdge(u, v, c), addEdge(v, u, 0);
    }
    void init()
    {
        s = 0, t = n + m + 1;
        for (int i = 1; i <= n; i++)
        {
            insert(0, i, r[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            insert(i + n, t, c[i]);
        }
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= m; v++)
            {
                insert(u, v + n, 1);
            }
        }
    }
    int d[MAXP], now[MAXP];
    bool build()
    {
        std::queue<int> q;
        std::memset(d, 0, sizeof(d));
        std::memset(now, 0, sizeof(now));
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
    int dinic(int u, int flow)
    {
        if (u == t)
        {
            return flow;
        }
        int rest = flow;
        for (int i = now[u]; i < g[u].size() && rest != 0; i++)
        {
            Edge &e = edge[g[u][i]], &ee = edge[g[u][i] ^ 1];
            if (e.cap != 0 && d[e.to] == d[u] + 1)
            {
                int add = dinic(e.to, std::min(e.cap, rest));
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
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &r[i]);
            r[0] += r[i];
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &c[i]);
        }
        init();
        while (build())
        {
            int flow = 0;
            while ((flow = dinic(s, INF)) != 0)
            {
                maxflow += flow;
            }
        }
        if (maxflow < r[0])
        {
            puts("0");
            return 0;
        }
        for (auto &e : edge)
        {
            if (1 <= e.from && e.from <= n && n + 1 <= e.to && e.to <= n + m)
            {
                if (e.cap == 0)
                {
                    ans[e.from].push_back(e.to);
                }
            }
        }
        puts("1");
        for (int i = 1; i <= n; i++)
        {
            for (auto &v : ans[i])
            {
                printf("%d ", v - n);
            }
            printf("\n");
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}