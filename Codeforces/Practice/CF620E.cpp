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
    const int MAXN = 4e5 + 5;
    using input::read;
    using output::write;
    int n, m;
    int root;
    int c[MAXN];
    int fa[MAXN];
    int tot = 0;
    int dfn[MAXN];
    int L[MAXN], R[MAXN];
    struct Node
    {
        LL tag;
        LL color;
    };
    Node node[MAXN << 2];
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
    void dfs(int u)
    {
        L[u] = ++tot, dfn[tot] = u;
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (!fa[e.to])
            {
                fa[e.to] = u;
                dfs(e.to);
            }
        }
        R[u] = tot;
    }
    void pushup(int o, int l, int r)
    {
        node[o].color = node[o << 1].color | node[o << 1 | 1].color;
    }
    void pushdown(int o, int l, int r)
    {
        if (node[o].tag)
        {
            node[o << 1].tag = node[o << 1 | 1].tag = node[o << 1].color = node[o << 1 | 1].color = node[o].tag;
            node[o].tag = 0;
        }
    }
    void build(int o, int l, int r)
    {
        if (l == r)
        {
            node[o].color = 1LL << (c[dfn[l]] - 1);
            return;
        }
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        pushup(o, l, r);
    }
    void update(int o, int l, int r, int ql, int qr, int v)
    {
        if (ql <= l && r <= qr)
        {
            node[o].color = node[o].tag = 1LL << (v - 1);
            return;
        }
        pushdown(o, l, r);
        int mid = (l + r) >> 1;
        if (mid >= ql)
        {
            update(o << 1, l, mid, ql, qr, v);
        }
        if (mid < qr)
        {
            update(o << 1 | 1, mid + 1, r, ql, qr, v);
        }
        pushup(o, l, r);
    }
    LL query(int o, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return node[o].color;
        }
        pushdown(o, l, r);
        LL res = 0;
        int mid = (l + r) >> 1;
        if (mid >= ql)
        {
            res = res | query(o << 1, l, mid, ql, qr);
        }
        if (mid < qr)
        {
            res = res | query(o << 1 | 1, mid + 1, r, ql, qr);
        }
        return res;
    }
    int popcount(LL x)
    {
        int res = 0;
        while (x)
        {
            if (x & 1)
            {
                res++;
            }
            x = x >> 1;
        }
        return res;
    }
    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(c[i]);
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            read(u, v);
            addEdge(u, v), addEdge(v, u);
        }
        fa[1] = -1;
        dfs(1);
        build(1, 1, n);
        for (int i = 1; i <= m; i++)
        {
            int op;
            read(op);
            if (op == 1)
            {
                int u, x;
                read(u, x);
                // write(L[u], R[u]);
                update(1, 1, n, L[u], R[u], x);
            }
            if (op == 2)
            {
                int u;
                read(u);
                // write(L[u], R[u]);
                write(popcount(query(1, 1, n, L[u], R[u])));
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