#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e4 + 5;
    const int MAXP = 1e5 + 5;
    const int INF = 0x3f3f3f3f;
    int n, m, t;
    int ans = 0;
    int maxflow = 0;
    struct Edge
    {
        int from, to, cap, id;
        Edge(int _from, int _to, int _cap, int _id) : from(_from), to(_to), cap(_cap), id(_id) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXP];
    void addEdge(int u, int v, int c, int id)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, c, id));
    }
    int d[MAXP], now[MAXP];
    bool build()
    {
        std::queue<int> q;
        std::memset(d, 0, sizeof(d));
        std::memset(now, 0, sizeof(now));
        q.push(0), d[0] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == n + m + 1)
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
        if (u == n + m + 1)
        {
            return flow;
        }
        int rest = flow;
        for (int i = now[u]; rest != 0 && i < g[u].size(); i++)
        {
            now[u] = i;
            Edge &e = edge[g[u][i]];
            Edge &ee = edge[g[u][i] ^ 1];
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
    int dfn_tot = 0, color_tot = 0;
    bool isinsta[MAXP];
    std::stack<int> stk;
    int dfn[MAXP], low[MAXP], color[MAXP];
    void push(int u)
    {
        isinsta[u] = true;
        stk.push(u);
    }
    int pop()
    {
        int x = stk.top();
        stk.pop(), isinsta[x] = false;
        return x;
    }
    void tarjan(int u)
    {
        push(u), dfn[u] = low[u] = ++dfn_tot;
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (e.cap == 0)
            {
                continue;
            }
            if (dfn[e.to] != 0 && isinsta[e.to] == true)
            {
                low[u] = std::min(low[u], low[e.to]);
            }
            if (dfn[e.to] == 0)
            {
                tarjan(e.to);
                low[u] = std::min(low[u], low[e.to]);
            }
        }
        if (low[u] == dfn[u])
        {
            color_tot++;
            while (stk.top() != u)
            {
                color[pop()] = color_tot;
            }
            color[pop()] = color_tot;
        }
    }
    int main()
    {
#ifdef LOCAL
        freopen("P8400.in", "r", stdin);
        freopen("P8400.out", "w", stdout);
#endif
        scanf("%d%d%d", &n, &m, &t);
        for (int i = 1; i <= t; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v + n, 1, i), addEdge(v + n, u, 0, i);
        }
        for (int i = 1; i <= n; i++)
        {
            addEdge(0, i, 1, -1), addEdge(i, 0, 0, -1);
        }
        for (int i = 1; i <= m; i++)
        {
            addEdge(i + n, n + m + 1, 1, -1), addEdge(n + m + 1, i + n, 0, -1);
        }
        int flow = 0;
        while (build())
        {
            while ((flow = dinic(0, INF)) != 0)
            {
                maxflow += flow;
            }
        }
        for (int i = 0; i <= n + m + 1; i++)
        {
            if (dfn[i] == 0)
            {
                tarjan(i);
            }
        }
        for (auto &e : edge)
        {
            if (1 <= e.from && e.from <= n && 1 + n <= e.to && e.to <= m + n)
            {
                if (e.cap != 0 && color[e.from] != color[e.to])
                {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
        for (auto &e : edge)
        {
            if (1 <= e.from && e.from <= n && 1 + n <= e.to && e.to <= m + n)
            {
                if (e.cap != 0 && color[e.from] != color[e.to])
                {
                    printf("%d ", e.id);
                }
            }
        }
        printf("\n");
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}