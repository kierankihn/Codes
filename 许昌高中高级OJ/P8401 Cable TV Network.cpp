#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 50 + 5;
    const int MAXP = 1000 + 5;
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
    void addEdge(int u, int v, int c)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, c));
    }
    void parse(std::string s)
    {
        int u = std::stoi(s.substr(1, s.find(',') - 1));
        int v = std::stoi(s.substr(s.find(',') + 1, s.size() - s.find(',') - 1));
        u++, v++;
        addEdge(u + n, v, INF), addEdge(v, u + n, 0);
        addEdge(v + n, u, INF), addEdge(u, v + n, 0);
    }
    void init()
    {
        ans = INF;
        edge.clear();
        for (int i = 1; i <= 2 * n; i++)
        {
            g[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            addEdge(i, i + n, 1), addEdge(i + n, i, 0);
        }
    }
    int d[MAXP], now[MAXP];
    bool build()
    {
        std::queue<int> q;
        std::memset(d, 0, sizeof(d));
        std::memset(now, 0, sizeof(now));
        d[s] = 1, q.push(s);
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
    int main()
    {
        while (std::cin >> n >> m)
        {
            init();
            for (int i = 1; i <= m; i++)
            {
                std::string s;
                std::cin >> s;
                parse(s);
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    s = i + n, t = j;
                    int maxflow = 0;
                    for (int i = 0; i < edge.size(); i += 2)
                    {
                        edge[i].cap += edge[i ^ 1].cap, edge[i ^ 1].cap = 0;
                    }
                    while (build())
                    {
                        int flow;
                        while ((flow = dinic(s, INF)) != 0)
                        {
                            maxflow += flow;
                        }
                    }
                    ans = std::min(ans, maxflow);
                }
            }
            if (ans >= 1e9)
            {
                ans = n;
            }
            printf("%d\n", ans);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}