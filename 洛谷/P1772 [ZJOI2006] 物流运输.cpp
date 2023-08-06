#include <bits/stdc++.h>
namespace input
{
    template <typename T>
    void read(T &x)
    {
        T res = 0, s = 1;
        char ch;
        while ((ch = getchar()) < '0' || ch > '9')
            if (ch == '-')
                s = -1;
        while (ch >= '0' && ch <= '9')
            res = res * 10 + ch - '0', ch = getchar();
        x = res * s;
    }
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        read(first);
        read(rest...);
    }
}
namespace output
{
    void write()
    {
        putchar('\n');
    }
    void write(char ch)
    {
        putchar(ch);
    }
    template <typename T>
    void write(char delimiter, T x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            write(delimiter, x / 10);
        putchar((x % 10) + '0');
    }
    template <typename First, typename... Rest>
    void write(char delimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
    }
    template <typename First, typename... Rest>
    void write(char delimiter, char linedelimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
        putchar(linedelimiter);
    }
    template <typename... T>
    void write(T... t)
    {
        write(' ', '\n', t...);
    }
}
namespace solution
{
    typedef long long LL;
    const LL INF = 0x3f3f3f3f3f3f3f3f;
    const int MAXN = 100 + 5;
    using input::read;
    using output::write;
    struct Edge
    {
        int from, to, dis;
        Edge(int u, int v, int d) : from(u), to(v), dis(d) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXN];
    void addEdge(int u, int v, int d)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, d));
    }
    LL n, m, k, e, cnt;
    bool ban[MAXN][MAXN];
    bool vis[MAXN];
    int dist[MAXN];
    LL isinque[MAXN];
    LL co[MAXN][MAXN], dp[MAXN];
    void SPFA()
    {
        std::memset(dist, 0x3f, sizeof(dist));
        std::memset(isinque, 0, sizeof(isinque));
        std::queue<int> q;
        q.push(1), dist[1] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            isinque[u] = false;
            if (vis[u] == false)
            {
                continue;
            }
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                if (dist[u] + e.dis < dist[e.to])
                {
                    dist[e.to] = dist[u] + e.dis;
                    if (!isinque[e.to])
                    {
                        isinque[e.to] = true;
                        q.push(e.to);
                    }
                }
            }
        }
    }
    int main()
    {
        read(n, m, k, e);
        for (int i = 1; i <= e; i++)
        {
            int u, v, d;
            read(u, v, d);
            addEdge(u, v, d), addEdge(v, u, d);
        }
        read(cnt);
        for (int i = 1; i <= cnt; i++)
        {
            int p, a, b;
            read(p, a, b);
            for (int j = a; j <= b; j++)
            {
                ban[p][j] = true;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                memset(vis, true, sizeof(vis));
                for (int p = 1; p <= m; p++)
                {
                    for (int q = i; q <= j; q++)
                    {
                        if (ban[p][q])
                        {
                            vis[p] = false;
                        }
                    }
                }
                SPFA();
                co[i][j] = dist[m];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i] = co[1][i] * i;
            for (int j = i - 1; j >= 0; j--)
            {
                dp[i] = std::min(dp[i], dp[j] + co[j + 1][i] * (i - j) + k);
                // write(i, j, dp[j], co[j + 1][i], dp[i]);
            }
        }
        write(dp[n]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}