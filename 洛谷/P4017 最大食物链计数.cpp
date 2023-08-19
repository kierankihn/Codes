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
    const int MAXN = 5000 + 5;
    const int MOD = 80112002;
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
    int n, m;
    int ans = 0;
    int res[MAXN];
    int ind[MAXN];
    std::vector<int> du0;
    std::queue<int> q;
    int main()
    {
        read(n, m);
        for (int i = 1; i <= m; i++)
        {
            int u, v, d = 1;
            read(u, v);
            addEdge(u, v, d), ind[v]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (g[i].size() == 0)
            {
                du0.push_back(i);
            }
            if (ind[i] == 0)
            {
                res[i] = 1;
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                res[e.to] += res[u];
                res[e.to] %= MOD;
                ind[e.to]--;
                if (ind[e.to] == 0)
                {
                    q.push(e.to);
                }
            }
        }
        for (auto &i : du0)
        {
            ans += res[i];
            ans %= MOD;
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