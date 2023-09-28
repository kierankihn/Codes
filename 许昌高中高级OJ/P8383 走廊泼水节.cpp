#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 6000;
    int t;
    int n;
    int fa[MAXN];
    int sum[MAXN];
    LL ans = 0;
    struct Edge
    {
        int from, to, dis;
        Edge(int _from, int _to, int _dis) : from(_from), to(_to), dis(_dis) {}
    };
    bool operator<(const Edge a, const Edge b)
    {
        return a.dis < b.dis;
    }
    std::vector<Edge> edge;
    void addEdge(int u, int v, int d)
    {
        edge.push_back(Edge(u, v, d));
    }
    int find(int x)
    {
        if (fa[x] == x)
        {
            return x;
        }
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y)
    {
        fa[y] = x, sum[x] += sum[y];
    }
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            scanf("%d", &n);
            ans = 0;
            edge.clear();
            for (int i = 1; i <= n; i++)
            {
                fa[i] = i, sum[i] = 1;
            }
            for (int i = 1; i < n; i++)
            {
                int u, v, d;
                scanf("%d%d%d", &u, &v, &d);
                addEdge(u, v, d);
            }
            std::sort(edge.begin(), edge.end());
            for (auto &e : edge)
            {
                int u = find(e.from), v = find(e.to);
                if (u == v)
                {
                    continue;
                }
                ans += (e.dis + 1) * (sum[u] * sum[v] - 1);
                merge(u, v);
            }
            printf("%lld\n", ans);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}