#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 40000 + 5;
    const double eps = 1e-7;
    struct Point
    {
        int x, y;
        Point() {}
        Point(int _x, int _y) : x(_x), y(_x) {}
    };
    int tot = 0;
    int n, m;
    double t1, t2, v;
    Point p1[MAXN], p2[MAXN];
    std::vector<int> e[MAXN];
    double getDis(Point x, Point y)
    {
        return std::sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
    }
    void build(double x)
    {
        for (int i = 1; i <= tot; i++)
        {
            e[i].clear();
        }
        tot = m;
        for (int i = 1; i <= n; i++)
        {
            for (double t = t1, cnt = 0; t <= x && cnt <= m; t += t1 + t2, cnt++)
            {
                tot++;
                for (int j = 1; j <= m; j++)
                {
                    if (t + getDis(p2[i], p1[j]) / v <= x)
                    {
                        e[j].push_back(tot);
                    }
                }
            }
        }
    }
    int match[MAXN];
    bool vis[MAXN];
    bool dfs(int u)
    {
        for (auto &v : e[u])
        {
            if (vis[v] == false)
            {
                vis[v] = true;
                if (match[v] == 0 || dfs(match[v]))
                {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    bool check(double x)
    {
        std::memset(match, 0, sizeof(match));
        build(x);
        for (int i = 1; i <= m; i++)
        {
            std::memset(vis, 0, sizeof(vis));
            if (dfs(i) == false)
            {
                return false;
            }
        }
        return true;
    }
    int main()
    {
        scanf("%d%d%lf%lf%lf", &n, &m, &t1, &t2, &v);
        t1 = t1 / 60;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &p1[i].x, &p1[i].y);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &p2[i].x, &p2[i].y);
        }
        double l = 0, r = 1e6;
        while (l + eps < r)
        {
            double mid = (l + r) / 2;
            if (check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        printf("%.6lf\n", l);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}