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
    const LL INF = 0x3f3f3f3f3f3f3f3fLL;
    using input::read;
    using output::write;
    struct Edge
    {
        LL from, to, dis;
        Edge(LL u, LL v, LL d) : from(u), to(v), dis(d) {}
    };
    std::vector<Edge> edge;
    std::vector<int> g[MAXN];
    void addEdge(LL u, LL v, LL d)
    {
        g[u].push_back(edge.size());
        edge.push_back(Edge(u, v, d));
    }
    int n, m;
    LL ans = -INF;
    LL res[MAXN];
    bool isinque[MAXN];
    std::queue<int> q;
    int main()
    {
        read(n, m);
        for (int i = 1; i <= m; i++)
        {
            int u, v, d;
            read(u, v, d);
            addEdge(u, v, d);
        }
        for (int i = 2; i <= n; i++)
        {
            res[i] = -INF;
        }
        q.push(1);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            isinque[u] = false;
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                res[e.to] = std::max(res[e.to], res[u] + e.dis);
                if (!isinque[e.to])
                {
                    q.push(e.to);
                    isinque[e.to] = true;
                }
            }
        }
        write(res[n] == -INF ? -1 : res[n]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}