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
    const int MAXN = 30 + 5;
    const int MAXP = MAXN * MAXN;
    const int DIR = 8;
    const int dx[DIR] = {1, 1, -1, -1, 2, 2, -2, -2};
    const int dy[DIR] = {2, -2, 2, -2, 1, -1, 1, -1};
    using input::read;
    using output::write;
    int n, m;
    int s, t;
    int map[MAXN][MAXN];
    struct Edge
    {
        int from, to, dis;
        Edge(int u, int v, int d) : from(u), to(v), dis(d) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXP];
    void addEdge(int u, int v, int d)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, d));
    }
    int getPointId(int x, int y)
    {
        return m * (x - 1) + y;
    }
    bool checkPointIsInRange(int x, int y)
    {
        return 0 < x && x <= n && 0 < y && y <= m;
    }
    bool vis[MAXN][MAXN];
    void dfs(int id, int x, int y)
    {
        vis[x][y] = true;
        for (int i = 0; i < DIR; i++)
        {
            int newx = x + dx[i], newy = y + dy[i];
            if (checkPointIsInRange(newx, newy) && !vis[newx][newy])
            {
                if (map[newx][newy] == 1)
                {
                    dfs(id, newx, newy);
                }
                if (map[newx][newy] != 1 && map[newx][newy] != 2)
                {
                    vis[newx][newy] = true;
                    addEdge(id, getPointId(newx, newy), 1);
                }
            }
        }
    }
    bool isInQueue[MAXP];
    LL dist[MAXP], cnt[MAXP];
    std::queue<int> q;
    void SPFA()
    {
        std::memset(dist, 0x3f, sizeof(dist));
        q.push(s), dist[s] = 0, cnt[s] = 1, isInQueue[s] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            isInQueue[u] = false;
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                // write(u, e.to);
                if (dist[u] + e.dis == dist[e.to])
                {
                    // write(u, e.to, cnt[u], cnt[e.to], dist[u], dist[e.to]);
                    cnt[e.to] += cnt[u];
                }
                if (dist[u] + e.dis < dist[e.to])
                {
                    dist[e.to] = dist[u] + e.dis;
                    cnt[e.to] = cnt[u];
                    if (!isInQueue[e.to])
                    {
                        q.push(e.to);
                    }
                }
            }
        }
    }
    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                read(map[i][j]);
                if (map[i][j] == 3)
                {
                    s = getPointId(i, j);
                }
                if (map[i][j] == 4)
                {
                    t = getPointId(i, j);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (map[i][j] == 0 || map[i][j] == 3)
                {
                    std::memset(vis, 0, sizeof(vis));
                    dfs(getPointId(i, j), i, j);
                }
            }
        }
        SPFA();
        if (dist[t] >= INF)
        {
            write(-1);
        }
        else
        {
            write(dist[t] - 1), write(cnt[t]);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}