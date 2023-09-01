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
    const int MAXN = 200000 + 5;
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
    int root = 1;
    int pos[MAXN];
    int dep[MAXN];
    int fa[MAXN];
    int dist[MAXN];
    void getPos(int x)
    {
        int u = x, fa = 0;
        for (int i = 1; i < n; i++)
        {
            pos[u] = pos[fa] + 1;
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                if (e.to != fa)
                {
                    fa = u, u = e.to;
                    break;
                }
            }
        }
    }
    void dfs(int u, int father)
    {
        fa[u] = father, dep[u] = dep[father] + 1;
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (e.to != father)
            {
                dfs(e.to, u);
            }
        }
    }
    int bfs(int x, int y)
    {
        int res = 0;
        std::memset(dist, 0, sizeof(dist));
        std::queue<int> q;
        int tmp = x;
        for (int i = 1; i < y; i++)
        {
            tmp = fa[tmp];
        }
        q.push(x);
        dist[x] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            res = std::max(res, dist[u] - 1);
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                if (!dist[e.to] && (u != tmp || e.to != fa[tmp]))
                {
                    q.push(e.to);
                    dist[e.to] = dist[u] + 1;
                }
            }
        }
        return res;
    }
    int main()
    {
        std::freopen("pass.in", "r", stdin);
        std::freopen("pass.out", "w", stdout);
        read(n);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            read(u, v);
            addEdge(u, v), addEdge(v, u);
        }
        for (int i = 1; i <= n; i++)
        {
            if (g[i].size() == 1)
            {
                getPos(i);
                break;
            }
        }
        read(m);
        dfs(1, 0);
        for (int i = 1; i <= m; i++)
        {
            char op;
            std::cin >> op;
            if (op == 'C')
            {
                read(root);
                if (n <= 3000)
                {
                    dfs(root, 0);
                }
            }
            if (op == 'Q')
            {
                int x, y;
                read(x, y);
                if (n <= 3000)
                {
                    write(bfs(x, y));
                }
                else
                {
                    if (pos[x] < pos[root])
                    {
                        write(std::max(pos[x] - 1, ((pos[x] + y <= pos[root]) ? (y - 1) : (n - pos[x]))));
                    }
                    if (pos[x] > pos[root])
                    {
                        write(std::max(n - pos[x], ((pos[root] + y <= pos[x]) ? (y - 1) : (pos[x] - 1))));
                    }
                    if (pos[x] == pos[root])
                    {
                        write(std::max(n - pos[x], pos[x] - 1));
                    }
                }
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}