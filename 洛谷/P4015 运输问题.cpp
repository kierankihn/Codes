#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e3 + 5;
    const int INF = 0x3f3f3f3f;
    int n, m;
    int s, t;
    struct Edge
    {
        int from, to, cap, dis;
        Edge(int _from, int _to, int _cap, int _dis) : from(_from), to(_to), cap(_cap), dis(_dis) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXN];
    void addEdge(int u, int v, int c, int d)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, c, d));
    }
    void insert(int u, int v, int c, int d)
    {
        addEdge(u, v, c, d), addEdge(v, u, 0, -d);
    }
    int cost[MAXN][MAXN];
    int value[MAXN];
    void build(int x)
    {
        s = 0, t = n + m + 1;
        edge.clear();
        for (int i = s; i <= t; i++)
        {
            g[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            insert(s, i, value[i], 0);
        }
        for (int i = 1; i <= m; i++)
        {
            insert(i + n, t, value[i + n], 0);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                insert(i, j + n, INF, cost[i][j] * x);
                // printf("Edge: (from: %d, to: %d, cap: %d, dis: %d)\n", i, j + n, -1, cost[i][j] * x);
            }
        }
    }
    bool inque[MAXN];
    int incf[MAXN], pre[MAXN], dist[MAXN];
    bool SPFA()
    {
        std::queue<int> q;
        for (int i = s; i <= t; i++)
        {
            dist[i] = INF, inque[i] = false;
        }
        incf[s] = INF, dist[s] = 0, inque[s] = true, q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop(), inque[u] = false;
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                if (e.cap != 0 && dist[u] + e.dis < dist[e.to])
                {
                    dist[e.to] = dist[u] + e.dis;
                    incf[e.to] = std::min(incf[u], e.cap), pre[e.to] = i;
                    if (inque[e.to] == false)
                    {
                        inque[e.to] = true, q.push(e.to);
                    }
                }
            }
        }
        if (dist[t] == INF)
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
            edge[pre[u]].cap -= incf[t], edge[pre[u] ^ 1].cap += incf[t], u = edge[pre[u]].from;
        }
        return dist[t] * incf[t];
    }
    int solve(int x)
    {
        int res = 0;
        build(x);
        while (SPFA())
        {
            res += update();
        }
        return res;
    }
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &value[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &value[i + n]);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &cost[i][j]);
            }
        }
        printf("%d\n", solve(1));
        printf("%d\n", -1 * solve(-1));
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}