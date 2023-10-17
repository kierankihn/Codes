#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 20 + 5;
    const int MAXM = 100 + 5;
    const int MAXP = (1 << 20) + 5;
    const int INF = 0x3f3f3f3f;
    int n, m;
    int s, t;
    bool vis[MAXP];
    int dist[MAXP];
    int cost[MAXM];
    int b1[MAXM], b2[MAXM], f1[MAXM], f2[MAXM];
    struct Node
    {
        int dis, id;
        Node(int _dis = 0, int _id = 0) : dis(_dis), id(_id) {}
    };
    bool operator>(const Node a, const Node b)
    {
        return a.dis > b.dis;
    }
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> q;
    void dijkstra()
    {
        std::memset(dist, 0x3f, sizeof(dist));
        dist[s] = 0, q.push(Node(0, s));
        while (!q.empty())
        {
            auto u = q.top().id;
            q.pop();
            if (u == t)
            {
                break;
            }
            if (vis[u] == true)
            {
                continue;
            }
            vis[u] = true;
            for (int i = 1; i <= m; i++)
            {
                if (((u & b1[i]) == b1[i]) && ((u & b2[i]) == 0))
                {
                    int v = (u & (~f2[i])) | f1[i];
                    if (dist[u] + cost[i] < dist[v])
                    {
                        dist[v] = dist[u] + cost[i];
                        q.push(Node(dist[v], v));
                    }
                }
            }
        }
    }
    int main()
    {
        scanf("%d%d", &n, &m);
        s = (1 << n) - 1, t = 0;
        for (int i = 1; i <= m; i++)
        {
            char b[MAXN], f[MAXN];
            scanf("%d%s%s", &cost[i], b + 1, f + 1);
            for (int j = 1; j <= n; j++)
            {
                b1[i] <<= 1, b2[i] <<= 1, f1[i] <<= 1, f2[i] <<= 1;
                if (b[j] == '+')
                {
                    b1[i] |= 1;
                }
                if (b[j] == '-')
                {
                    b2[i] |= 1;
                }
                if (f[j] == '+')
                {
                    f1[i] |= 1;
                }
                if (f[j] == '-')
                {
                    f2[i] |= 1;
                }
            }
        }
        dijkstra();
        printf("%d\n", dist[t] == INF ? 0 : dist[t]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}