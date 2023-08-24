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
    const int MAXN = 1500 + 5;
    const int INF = 0x3f3f3f3f;
    using input::read;
    using output::write;
    struct Edge
    {
        int from;
        int to;
        int dis;
        Edge(int u, int v, int d) : from(u), to(v), dis(d)
        {
            // nothing
        }
    };
    int n;
    int root;
    int fa[MAXN];
    int nums[MAXN];
    int dp[MAXN][3];
    std::vector<Edge> edge;
    std::vector<int> g[MAXN + 5];
    void addEdge(int u, int v, int d)
    {
        edge.push_back(Edge(u, v, d));
        g[u].push_back(edge.size() - 1);
    }
    int solve(int u, int k)
    {
        if (dp[u][k] != -1)
        {
            return dp[u][k];
        }
        dp[u][k] = 0;
        int d = INF;
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (k == 0)
            {
                dp[u][k] += std::min(solve(e.to, 0), solve(e.to, 2));
                d = std::min(d, solve(e.to, 2) - std::min(solve(e.to, 0), solve(e.to, 2)));
            }
            if (k == 1)
            {
                dp[u][k] += std::min(solve(e.to, 0), solve(e.to, 2));
            }
            if (k == 2)
            {
                dp[u][k] += std::min(solve(e.to, 0), std::min(solve(e.to, 1), solve(e.to, 2)));
            }
        }
        if (k == 0)
        {
            dp[u][k] += d;
        }
        if (k == 2)
        {
            dp[u][k] += nums[u];
        }
        return dp[u][k];
    }
    int main()
    {
        memset(dp, -1, sizeof(dp));
        read(n);
        for (int i = 1; i <= n; i++)
        {
            int u, v, cnt;
            read(u);
            read(nums[u], cnt);
            for (int i = 1; i <= cnt; i++)
            {
                read(v);
                addEdge(u, v, 0);
                fa[v] = u;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!fa[i])
            {
                root = i;
                break;
            }
        }
        write(std::min(solve(root, 0), solve(root, 2)));
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}