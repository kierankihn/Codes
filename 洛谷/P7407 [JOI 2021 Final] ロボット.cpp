#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e6 + 5;
    const LL INF = 0x3f3f3f3f3f3f3f3f;
    int n, m;
    int tot = 0;
    LL sum[MAXN], col[MAXN];
    struct Edge
    {
        int from, to, color;
        LL dis;
        Edge(int _from, int _to, int _color, LL _dis) : from(_from), to(_to), color(_color), dis(_dis) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXN];
    void addEdge(int u, int v, int c, LL d)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, c, d));
    }
    void build()
    {
        tot = n;
        for (int u = 1; u <= n; u++)
        {
            for (auto &i : g[u])
            {
                auto &e = edge[i];
                if (e.color == 0)
                {
                    continue;
                }
                sum[e.color] += e.dis;
            }
            auto tmp = g[u];
            for (auto &i : tmp)
            {
                auto e = edge[i];
                if (e.color == 0)
                {
                    continue;
                }
                if (col[e.color] == 0)
                {
                    col[e.color] = ++tot;
                    addEdge(u, col[e.color], 0, 0);
                }
                addEdge(col[e.color], e.to, 0, sum[e.color] - e.dis);
                addEdge(e.to, col[e.color], 0, 0);
            }
            for (auto &i : g[u])
            {
                auto &e = edge[i];
                sum[e.color] = 0, col[e.color] = 0;
            }
        }
    }
    struct Node
    {
        LL id, dis;
        Node(LL _id = 0, LL _dis = 0) : id(_id), dis(_dis) {}
    };
    bool operator>(const Node a, const Node b)
    {
        return a.dis > b.dis;
    }
    LL dist[MAXN];
    bool vis[MAXN];
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> q;
    void dijkstra()
    {
        std::memset(dist, 0x3f, sizeof(dist));
        dist[1] = 0, q.push(Node(1, 0));
        while (!q.empty())
        {
            auto u = q.top();
            q.pop();
            if (vis[u.id] == true)
            {
                continue;
            }
            vis[u.id] = true;
            for (auto &i : g[u.id])
            {
                auto &e = edge[i];
                if (u.dis + e.dis < dist[e.to])
                {
                    dist[e.to] = u.dis + e.dis;
                    q.push(Node(e.to, dist[e.to]));
                }
            }
        }
    }
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int u, v, c, d;
            scanf("%d%d%d%d", &u, &v, &c, &d);
            addEdge(u, v, c, d), addEdge(v, u, c, d);
        }
        build();
        dijkstra();
        printf("%lld\n", dist[n] == INF ? -1 : dist[n]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}