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
    using input::read;
    using output::write;
    int n, m;
    int ans = 0;
    struct Edge
    {
        int from, to, dis;
        Edge(int u, int v, int d) : from(u), to(v), dis(d) {}
    };
    std::vector<Edge> edge;
    int fa[MAXN];
    int find(int x)
    {
        int tmp = x;
        while (x != fa[x])
        {
            x = fa[x];
        }
        return fa[tmp] = fa[x];
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        fa[y] = x;
    }
    struct Cmp
    {
        bool operator()(const int a, const int b)
        {
            return edge[a].dis > edge[b].dis;
        }
    };
    std::priority_queue<int, std::vector<int>, Cmp> q;
    void check()
    {
        if (q.empty())
        {
            puts("orz");
            exit(0);
        }
    }
    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v, d;
            read(u, v, d);
            edge.push_back(Edge(u, v, d));
            q.push(i - 1);
        }
        for (int i = 1; i < n; i++)
        {
            check();
            Edge e = edge[q.top()];
            q.pop();
            while (find(e.from) == find(e.to))
            {
                check();
                e = edge[q.top()];
                q.pop();
            }
            ans += e.dis;
            merge(e.from, e.to);
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