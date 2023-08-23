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
    const int MAXN = 1000 + 5;
    const int LEN = 1000000;
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
    int n, p, k;
    int dist[MAXN];
    bool vis[MAXN];
    bool check(int x)
    {
        std::queue<int> q;
        std::memset(dist, 0x3f, sizeof(dist));
        q.push(1), dist[1] = 0, vis[1] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                if (dist[u] + (e.dis > x ? 1 : 0) < dist[e.to])
                {
                    dist[e.to] = dist[u] + (e.dis > x ? 1 : 0);
                    if (!vis[e.to])
                    {
                        q.push(e.to);
                        vis[e.to] = true;
                    }
                }
            }
        }
        return dist[n] <= k;
    }
    int main()
    {
        read(n, p, k);
        for (int i = 1; i <= p; i++)
        {
            int u, v, d;
            read(u, v, d);
            addEdge(u, v, d), addEdge(v, u, d);
        }
        int l = 0, r = LEN, ans = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        write(ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}