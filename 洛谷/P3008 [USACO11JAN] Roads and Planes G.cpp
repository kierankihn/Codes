#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 25000 + 5;
    const LL INF = 0x3f3f3f3f3f3f3f3fLL;
    std::deque<int> q;
    struct Edge
    {
        int from, to, dis;
        Edge(int _from, int _to, int _dis) : from(_from), to(_to), dis(_dis) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXN];
    void addEdge(int u, int v, int d)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, d));
    }
    int n, m, r, p, s;
    LL dist[MAXN], cnt[MAXN];
    bool SPFA()
    {
        std::memset(dist, 0x3f, sizeof(dist));
        dist[s] = 0;
        q.push_back(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop_front();
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                if (dist[u] + e.dis < dist[e.to])
                {
                    dist[e.to] = dist[u] + e.dis;
                    cnt[e.to] = cnt[u] + 1;
                    if (cnt[e.to] >= n)
                    {
                        return false;
                    }
                    if (q.empty() || dist[e.to] < dist[q.front()])
                    {
                        q.push_front(e.to);
                    }
                    else
                    {
                        q.push_back(e.to);
                    }
                }
            }
        }
        return true;
    }
    int main()
    {
        scanf("%d%d%d%d", &n, &r, &p, &s);
        for (int i = 1; i <= r; i++)
        {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            addEdge(u, v, d), addEdge(v, u, d);
        }
        for (int i = 1; i <= p; i++)
        {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            addEdge(u, v, d);
        }
        if(SPFA())
        {
            for (int i = 1; i <= n; i++)
            {
                if (dist[i] == INF)
                {
                    puts("NO PATH");
                }
                else
                {
                    printf("%lld\n", dist[i]);
                }
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                puts("NO PATH");
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}