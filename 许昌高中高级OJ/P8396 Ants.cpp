#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 100 + 5;
    const double INF = 1e10;
    const double eps = 1e-8;
    int n;
    struct Point
    {
        int x, y;
        Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    };
    double getDis(Point x, Point y)
    {
        return std::sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
    }
    int ans[MAXN];
    int match[MAXN];
    double upd[MAXN];
    Point p[MAXN][2];
    bool vis[MAXN][2];
    double mark[MAXN][2];
    double mp[MAXN][MAXN];
    void build()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                mp[i][j] = -getDis(p[i][0], p[j][1]);
            }
        }
    }
    bool dfs(int u)
    {
        vis[u][0] = true;
        for (int v = 1; v <= n; v++)
        {
            if (vis[v][1] == false)
            {
                if (std::fabs(mark[u][0] + mark[v][1] - mp[u][v]) <= eps)
                {
                    vis[v][1] = true;
                    if (match[v] == 0 || dfs(match[v]))
                    {
                        match[v] = u;
                        return true;
                    }
                }
                else
                {
                    upd[v] = std::min(upd[v], mark[u][0] + mark[v][1] - mp[u][v]);
                }
            }
        }
        return false;
    }
    void KM()
    {
        for (int i = 1; i <= n; i++)
        {
            mark[i][0] = -INF, mark[i][1] = 0;
            for (int j = 1; j <= n; j++)
            {
                mark[i][0] = std::max(mark[i][0], mp[i][j]);
            }
        }
        for (int u = 1; u <= n; u++)
        {
            while (true)
            {
                std::memset(vis, 0, sizeof(vis));
                double delta = INF;
                for (int i = 1; i <= n; i++)
                {
                    upd[i] = INF;
                }
                if (dfs(u))
                {
                    break;
                }
                for (int i = 1; i <= n; i++)
                {
                    if (vis[i][1] == false)
                    {
                        delta = std::min(delta, upd[i]);
                    }
                }
                for (int i = 1; i <= n; i++)
                {
                    if (vis[i][0])
                    {
                        mark[i][0] -= delta;
                    }
                    if (vis[i][1])
                    {
                        mark[i][1] += delta;
                    }
                }
            }
        }
    }
    int main()
    {
        scanf("%d", &n);
        for (int j = 0; j <= 1; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                scanf("%d%d", &p[i][j].x, &p[i][j].y);
            }
        }
        build();
        KM();
        for (int i = 1; i <= n; i++)
        {
            ans[match[i]] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d\n", ans[i]);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}