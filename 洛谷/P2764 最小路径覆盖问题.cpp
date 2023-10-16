#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 150 + 5;
    const int MAXP = 1e3 + 5;
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
    std::vector<int> g[MAXP];
    std::vector<int> mp[MAXP];
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
        ans = n, s = 0, t = n * 2 + 1;
        for (int i = 1; i <= n; i++)
        {
            insert(s, i, 1), insert(i + n, t, 1);
        }
        for (int u = 1; u <= n; u++)
        {
            for (auto &v : mp[u])
            {
                insert(u, v + n, 1);
            }
        }
    }
    int d[MAXP], now[MAXP];
    bool build()
    {
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
        for (int i = now[u]; rest != 0 && i < g[u].size(); i++)
        {
            now[u] = i;
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
    int fa[MAXP];
    int du[MAXP];
    void solve()
    {
        for (int i = 0; i < edge.size(); i += 2)
        {
            Edge &e = edge[i];
            if (e.from == s || e.to == s || e.from == t || e.to == t)
            {
                continue;
            }
            if (e.cap == 0)
            {
                fa[e.to - n] = e.from;
                du[e.from]++;
            }
        }
    }
    void print(int u)
    {
        printf("%d ", u);
        if (fa[u] != 0)
        {
            print(fa[u]);
        }
    }
    int main()
    {
#ifdef LOCAL
        freopen("P2764.in", "r", stdin);
#endif
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            mp[u].push_back(v);
        }
        init();
        while (build())
        {
            int flow = 0;
            while ((flow = dinic(s, INF)) != 0)
            {
                ans -= flow;
            }
        }
        solve();
        for (int i = 1; i <= n; i++)
        {
            if (du[i] == 0)
            {
                print(i);
                printf("\n");
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