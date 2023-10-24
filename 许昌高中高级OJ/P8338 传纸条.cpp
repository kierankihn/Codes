#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 50 + 5;
    const int MAXP = 5000 + 5;
    const int INF = 0x3f3f3f3f;
    int n, m;
    int s, t;
    int ans = 0;
    int maxflow = 0;
    int val[MAXN][MAXN];
    struct Edge
    {
        int from, to, cap, dis;
        Edge(int _from, int _to, int _cap, int _dis) : from(_from), to(_to), cap(_cap), dis(_dis) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXP];
    void addEdge(int u, int v, int c, int d)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, c, d));
    }
    void insert(int u, int v, int c, int d)
    {
        addEdge(u, v, c, d), addEdge(v, u, 0, -d);
    }
    int getId(int x, int y)
    {
        return (x - 1) * m + y;
    }
    void build()
    {
        s = 1, t = 2 * n * m;
        insert(1, 1 + n * m, 1, 0);
        insert(n * m, 2 * n * m, 1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                insert(getId(i, j), getId(i, j) + n * m, 1, val[i][j]);
                if (i + 1 <= n)
                {
                    insert(getId(i, j) + n * m, getId(i + 1, j), 1, 0);
                }
                if (j + 1 <= m)
                {
                    insert(getId(i, j) + n * m, getId(i, j + 1), 1, 0);
                }
            }
        }
    }
    bool inq[MAXP];
    int dist[MAXP], incf[MAXP], pre[MAXP];
    void init()
    {
        for (int i = s; i <= t; i++)
        {
            inq[i] = false, incf[i] = INF, dist[i] = -INF, pre[i] = 0;
        }
    }
    bool SPFA()
    {
        init();
        std::queue<int> q;
        q.push(s), inq[s] = true, dist[s] = 0, incf[s] = INF;
        while (!q.empty())
        {
            int u = q.front();
            q.pop(), inq[u] = false;
            for (auto &i : g[u])
            {
                auto &e = edge[i];
                if (e.cap != 0 && dist[u] + e.dis > dist[e.to])
                {
                    dist[e.to] = dist[u] + e.dis;
                    pre[e.to] = i, incf[e.to] = std::min(incf[u], e.cap);
                    if (inq[e.to] == false)
                    {
                        q.push(e.to), inq[e.to] = true;
                    }
                }
            }
        }
        if (dist[t] == -INF)
        {
            return false;
        }
        return true;
    }
    int update()
    {
        int u = t;
        while (u != s)
        {
            auto &e = edge[pre[u]], &ee = edge[pre[u] ^ 1];
            e.cap -= incf[t], ee.cap += incf[t], u = e.from;
        }
        maxflow += incf[t];
        return dist[t] * incf[t];
    }
    void EK()
    {
        while (SPFA())
        {
            ans += update();
        }
    }
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &val[i][j]);
            }
        }
        build();
        EK();
        printf("%d\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}