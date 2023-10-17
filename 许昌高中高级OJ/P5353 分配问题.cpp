#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e3 + 5;
    const int INF = 0x3f3f3f3f;
    int n;
    int s, t;
    int ans = 0;
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
    bool inque[MAXN];
    int dist[MAXN], incf[MAXN], pre[MAXN];
    void init(int x)
    {
        for (int i = 0; i <= 2 * n + 1; i++)
        {
            inque[i] = false, dist[i] = x;
        }
    }
    bool SPFA(std::function<bool(int, int)> check, int x)
    {
        init(x);
        std::queue<int> q;
        q.push(s), dist[s] = 0, incf[s] = INF;
        while (!q.empty())
        {
            int u = q.front();
            q.pop(), inque[u] = false;
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                if (e.cap != 0 && check(dist[u] + e.dis, dist[e.to]))
                {
                    dist[e.to] = dist[u] + e.dis, pre[e.to] = i, incf[e.to] = std::min(e.cap, incf[u]);
                    if (inque[e.to] == false)
                    {
                        inque[e.to] = true, q.push(e.to);
                    }
                }
            }
        }
        if (dist[t] == x)
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
            edge[pre[u]].cap -= incf[t], edge[pre[u] ^ 1].cap += incf[t], u = edge[pre[u]].from;
        }
        ans += incf[t] * dist[t];
    }
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int c;
                scanf("%d", &c);
                insert(i, j + n, 1, c);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            insert(0, i, 1, 0), insert(i + n, 2 * n + 1, 1, 0);
        }
        s = 0, t = 2 * n + 1;
        auto min = [](int a, int b)
        {
            return a < b;
        };
        auto max = [](int a, int b)
        {
            return a > b;
        };
        ans = 0;
        while (SPFA(min, INF))
        {
            update();
        }
        printf("%d\n", ans);
        ans = 0;
        for (int i = 0; i < edge.size(); i += 2)
        {
            edge[i].cap += edge[i + 1].cap, edge[i + 1].cap = 0;
        }
        while (SPFA(max, -INF))
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