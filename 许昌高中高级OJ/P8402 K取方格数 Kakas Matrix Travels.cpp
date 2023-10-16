#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 50 + 5;
    const int MAXK = 10 + 5;
    const int MAXP = 1e4 + 5;
    const int INF = 0x3f3f3f3f;
    int n, k;
    int s, t;
    int ans = 0;
    int maxflow = 0;
    int mp[MAXN][MAXN];
    struct Edge
    {
        int from, to, cap, cost;
        Edge(int _from, int _to, int _cap, int _cost) : from(_from), to(_to), cap(_cap), cost(_cost) {}
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
        return (x - 1) * n + y;
    }
    void build()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                insert(getId(i, j), getId(i, j) + n * n, 1, mp[i][j]);
                insert(getId(i, j), getId(i, j) + n * n, k - 1, 0);
                if (i + 1 <= n)
                {
                    insert(getId(i, j) + n * n, getId(i + 1, j), k, 0);
                }
                if (j + 1 <= n)
                {
                    insert(getId(i, j) + n * n, getId(i, j + 1), k, 0);
                }
            }
        }
    }
    bool inque[MAXP];
    int dist[MAXP], incf[MAXP], pre[MAXP];
    void init()
    {
        for (int i = 1; i <= 2 * n * n; i++)
        {
            dist[i] = -INF, inque[i] = false;
        }
    }
    bool SPFA()
    {
        init();
        std::queue<int> q;
        q.push(s), dist[s] = 0, inque[s] = true, incf[s] = INF;
        while (!q.empty())
        {
            int u = q.front();
            q.pop(), inque[u] = false;
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                if (e.cap != 0 && dist[u] + e.cost > dist[e.to])
                {
                    dist[e.to] = dist[u] + e.cost;
                    incf[e.to] = std::min(incf[u], e.cap);
                    pre[e.to] = i;
                    if (inque[e.to] == false)
                    {
                        inque[e.to] = true, q.push(e.to);
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
    void update()
    {
        int u = t;
        while (u != s)
        {
            edge[pre[u]].cap -= incf[t];
            edge[pre[u] ^ 1].cap += incf[t];
            u = edge[pre[u]].from;
        }
        maxflow += incf[t], ans += dist[t] * incf[t];
    }
    int main()
    {
        scanf("%d%d", &n, &k);
        s = 1, t = 2 * n * n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &mp[i][j]);
            }
        }
        build();
        while (SPFA())
        {
            update();
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