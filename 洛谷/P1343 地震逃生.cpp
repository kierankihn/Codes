#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXN = 2000 + 5;
    const i64 INF = 0x3f3f3f3f3f3f3f3fLL;
    int n, m, k;
    int s, t;
    i64 maxflow = 0;
    struct Edge
    {
        int from, to;
        i64 cap;
        Edge(int _from, int _to, i64 _cap) : from(_from), to(_to), cap(_cap) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXN];
    void addEdge(int u, int v, i64 c)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, c));
    }
    void insert(int u, int v, i64 c)
    {
        addEdge(u, v, c), addEdge(v, u, 0);
    }
    int d[MAXN], now[MAXN];
    bool build()
    {
        s = 1, t = n;
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
            for (auto i : g[u])
            {
                auto &e = edge[i];
                if (e.cap != 0 && d[e.to] == 0)
                {
                    d[e.to] = d[u] + 1, q.push(e.to);
                }
            }
        }
        return false;
    }
    i64 dinic(int u, i64 flow)
    {
        if (u == t)
        {
            return flow;
        }
        i64 rest = flow;
        for (size_t i = now[u]; i < g[u].size() && rest > 0; i++)
        {
            now[u] = i;
            auto &e = edge[g[u][i]], &ee = edge[g[u][i] ^ 1];
            if (e.cap > 0 && d[e.to] == d[u] + 1)
            {
                i64 add = dinic(e.to, std::min(rest, e.cap));
                rest -= add, e.cap -= add, ee.cap += add;
            }
        }
        return flow - rest;
    }
    int main()
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= m; i++)
        {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            insert(u, v, c);
        }
        while (build())
        {
            maxflow += dinic(s, INF);
        }
        if (maxflow == 0)
        {
            puts("Orz Ni Jinan Saint Cow!");
            exit(0);
        }
        printf("%lld %lld\n", maxflow, (i64)std::ceil((double)k / maxflow));
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}