#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 500 + 5;
    int t;
    int s, n;
    double ans = 0;
    struct Edge
    {
        int from, to;
        double dis;
        Edge(int _from, int _to, double _dis) : from(_from), to(_to), dis(_dis) {}
    };
    bool operator<(const Edge a, const Edge b)
    {
        return a.dis < b.dis;
    }
    std::vector<Edge> edge;
    void addEdge(int u, int v, double d)
    {
        edge.push_back(Edge(u, v, d));
    }
    struct Point
    {
        int x, y;
        Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    };
    Point p[MAXN];
    double getDist(Point x, Point y)
    {
        return std::sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
    }
    int fa[MAXN];
    int find(int x)
    {
        if (fa[x] == x)
        {
            return x;
        }
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y)
    {
        fa[y] = x;
    }
    void init()
    {
        ans = 0;
        edge.clear();
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
        }
    }
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            scanf("%d%d", &s, &n);
            s = n - s;
            init();
            for (int i = 1; i <= n; i++)
            {
                scanf("%d%d", &p[i].x, &p[i].y);
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    addEdge(i, j, getDist(p[i], p[j]));
                }
            }
            std::sort(edge.begin(), edge.end());
            for (auto &e : edge)
            {
                if (find(e.from) != find(e.to))
                {
                    if (--s == 0)
                    {
                        printf("%.2lf\n", e.dis);
                    }
                    merge(find(e.from), find(e.to));
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