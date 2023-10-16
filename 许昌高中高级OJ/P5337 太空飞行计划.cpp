#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 50 + 5;
    const int MAXP = 1e3 + 5;
    const int INF = 0x3f3f3f3f;
    int n, m;
    int s, t;
    int ans = 0;
    int maxflow = 0;
    int value[MAXN], cost[MAXN];
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
    void input()
    {
        std::cin >> n >> m;
        s = 0, t = n + m + 1;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> value[i];
            std::string s;
            std::cin.ignore();
            std::getline(std::cin, s);
            std::stringstream ss(s);
            int v;
            while (ss >> v)
            {
                addEdge(i, v + n, INF), addEdge(v + n, i, 0);
            }
            addEdge(0, i, value[i]), addEdge(i, 0, 0);
        }
        for (int i = 1; i <= m; i++)
        {
            std::cin >> cost[i];
            addEdge(i + n, n + m + 1, cost[i]), addEdge(n + m + 1, i + n, 0);
        }
    }
    int d[MAXP], now[MAXP];
    bool build()
    {
        std::queue<int> q;
        std::memset(d, 0, sizeof(d));
        std::memset(now, 0, sizeof(now));
        d[s] = 1, q.push(s);
        while (q.empty() != true)
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
            now[u] = i;
            Edge &e = edge[g[u][i]], &ee = edge[g[u][i] ^ 1];
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
    bool vis[MAXP], mark[MAXP];
    void bfs()
    {
        std::queue<int> q;
        q.push(s), vis[s] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                if (e.cap != 0 && vis[e.to] == false)
                {
                    vis[e.to] = true, q.push(e.to);
                }
            }
        }
    }
    int main()
    {
        input();
        while (build())
        {
            int flow = 0;
            while ((flow = dinic(s, INF)) != 0)
            {
                maxflow += flow;
            }
        }
        bfs();
        for (auto &e : edge)
        {
            if (vis[e.from] ^ vis[e.to])
            {
                mark[e.from] = mark[e.to] = true;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (mark[i] == false)
            {
                printf("%d ", i);
                ans += value[i];
            }
        }
        printf("\n");
        for (int i = 1; i <= m; i++)
        {
            if (mark[i + n] == true)
            {
                printf("%d ", i);
                ans -= cost[i];
            }
        }
        printf("\n");
        printf("%d\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}