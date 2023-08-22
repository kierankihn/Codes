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
    const int MAXN = 2000 + 5;
    const int INF = 0x3f3f3f3f;
    using input::read;
    using output::write;
    struct Edge
    {
        int from, to, dis;
        Edge(int u, int v, int d) : from(u), to(v), dis(d) {}
    };
    int mp[MAXN][MAXN];
    std::vector<Edge> edge;
    std::vector<int> g[MAXN];
    void addEdge(int u, int v, int d)
    {
        if (!mp[u][v])
        {
            g[u].push_back(edge.size());
            mp[u][v] = edge.size();
            edge.push_back(Edge(u, v, d));
        }
        else
        {
            edge[mp[u][v]] = Edge(u, v, std::min(d, edge[mp[u][v]].dis));
        }
    }
    int n, m;
    int cnt[MAXN];
    int dis[MAXN];
    int vis[MAXN];
    struct Cmp
    {
        bool operator()(const int a, const int b)
        {
            return dis[a] > dis[b];
        }
    };
    void solve()
    {
        std::memset(dis, 0x3f, sizeof(dis));
        std::priority_queue<int, std::vector<int>, Cmp> q;
        q.push(1), cnt[1] = 1, dis[1] = 0;
        while (!q.empty())
        {
            int u = q.top();
            q.pop();
            if (vis[u])
            {
                continue;
            }
            vis[u] = true;
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                if (dis[u] + e.dis == dis[e.to])
                {
                    cnt[e.to] += cnt[u];
                }
                if (dis[u] + e.dis < dis[e.to])
                {
                    dis[e.to] = dis[u] + e.dis;
                    cnt[e.to] = cnt[u];
                }
                if (!vis[e.to])
                {
                    q.push(e.to);
                }
            }
        }
    }
    int main()
    {
        read(n, m);
        for (int i = 1; i <= m; i++)
        {
            int u, v, d;
            read(u, v, d);
            addEdge(u, v, d);
        }
        solve();
        if (dis[n] < INF)
        {
            write(dis[n], cnt[n]);
        }
        else
        {
            puts("No answer");
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}