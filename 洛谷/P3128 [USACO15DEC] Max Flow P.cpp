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
    const int MAXN = 5e4 + 5;
    const int MAXLOGN = 20;
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
    int n, k;
    int ans = 0;
    int tag[MAXN];
    int dep[MAXN];
    int fa[MAXN][MAXLOGN];
    void dfs(int u, int father)
    {
        fa[u][0] = father, dep[u] = dep[father] + 1;
        for (int i = 1; i <= std::log2(dep[u] - 1); i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (e.to == father)
            {
                continue;
            }
            dfs(e.to, u);
        }
    }
    int LCA(int x, int y)
    {
        if (dep[x] < dep[y])
        {
            std::swap(x, y);
        }
        while (dep[x] > dep[y])
        {
            x = fa[x][(int)std::log2(dep[x] - dep[y])];
        }
        if (x == y)
        {
            return x;
        }
        for (int i = std::log2(dep[x]); i >= 0; i--)
        {
            if (fa[x][i] != fa[y][i])
            {
                x = fa[x][i], y = fa[y][i];
            }
        }
        return fa[x][0];
    }
    void solve(int u)
    {
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (e.to == fa[u][0])
            {
                continue;
            }
            solve(e.to);
            tag[u] += tag[e.to];
        }
        ans = std::max(ans, tag[u]);
    }
    int main()
    {
        read(n, k);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            read(u, v);
            addEdge(u, v), addEdge(v, u);
        }
        dfs(1, 0);
        for (int i = 1; i <= k; i++)
        {
            int s, t, father;
            read(s, t);
            father = LCA(s, t);
            tag[s]++, tag[t]++;
            tag[father]--, tag[fa[father][0]]--;
        }
        solve(1);
        write(ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}