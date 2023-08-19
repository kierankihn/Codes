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
    const int MAXN = 1e5 + 5;
    using input::read;
    using output::write;
    int t;
    int n, m;
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
    int in[MAXN];
    std::vector<int> ans;
    std::priority_queue<int> q;
    void init()
    {
        std::memset(in, 0, sizeof(in));
        edge.clear();
        ans.clear();
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
        }
    }
    void topo()
    {
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int u = q.top();
            q.pop();
            ans.push_back(u);
            for (auto &i : g[u])
            {
                Edge &e = edge[i];
                in[e.to]--;
                if (in[e.to] == 0)
                {
                    q.push(e.to);
                }
            }
        }
    }
    int main()
    {
        read(t);
        while (t--)
        {
            init();
            read(n, m);
            for (int i = 1; i <= m; i++)
            {
                int u, v;
                read(v, u);
                addEdge(u, v);
                in[v]++;
            }
            topo();
            if (ans.size() != (unsigned int)n)
            {
                puts("Impossible!");
            }
            else
            {
                for (int i = n - 1; i >= 0; i--)
                {
                    std::cout << ans[i] << " ";
                }
                std::cout << std::endl;
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