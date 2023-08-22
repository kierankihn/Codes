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
    const int MAXN = 1e6 + 5;
    const int MOD = 100003;
    using input::read;
    using output::write;
    struct Edge
    {
        int from, to;
        Edge(int u, int v) : from(u), to(v) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXN];
    void addEdge(int u, int v)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v));
    }
    int n, m;
    int cnt[MAXN];
    int dis[MAXN];
    int vis[MAXN];
    void bfs()
    {
        std::memset(dis, 0x3f, sizeof(dis));
        std::queue<int> q;
        q.push(1), vis[1] = 1, cnt[1] = 1, dis[1] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = 2;
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                if (vis[e.to] == 0)
                {
                    q.push(e.to);
                    vis[e.to] = 1;
                }
                if (vis[e.to] != 2)
                {
                    if (dis[u] + 1 == dis[e.to])
                    {
                        cnt[e.to]+= cnt[u];
                    }
                    if (dis[u] + 1 < dis[e.to])
                    {
                        dis[e.to] = dis[u] + 1;
                        cnt[e.to] = cnt[u];
                    }
                }
                cnt[e.to] %= MOD;
            }
        }
    }
    int main()
    {
        read(n, m);
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            read(u, v);
            addEdge(u, v), addEdge(v, u);
        }
        bfs();
        for (int i = 1; i <= n; i++)
        {
            write(cnt[i]);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}