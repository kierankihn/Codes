#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 3e5 + 5;
    int n, s;
    LL t[MAXN], c[MAXN];
    LL sumt[MAXN], sumc[MAXN];
    LL dp[MAXN];
    struct Point
    {
        LL x, y;
        Point(LL _x = 0, LL _y = 0) : x(_x), y(_y) {}
    };
    std::deque<Point> q;
    double slope(Point x, Point y)
    {
        return (double)(x.y - y.y) / (x.x - y.x);
    }
    int main()
    {
        scanf("%d%d", &n, &s);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld", &t[i], &c[i]);
            sumt[i] = sumt[i - 1] + t[i], sumc[i] = sumc[i - 1] + c[i];
        }
        q.push_back(Point(0, 0));
        for (int i = 1; i <= n; i++)
        {
            while (q.size() >= 2 && slope(q[0], q[1]) < sumt[i] + s)
            {
                q.pop_front();
            }
            if (!q.empty())
            {
                dp[i] = q.front().y + sumt[i] * sumc[i] - (sumt[i] + s) * q.front().x + s * sumc[n];
            }
            while (q.size() >= 2 && slope(Point(sumc[i], dp[i]), q[q.size() - 1]) < slope(q[q.size() - 1], q[q.size() - 2]))
            {
                q.pop_back();
            }
            q.push_back(Point(sumc[i], dp[i]));
        }
        printf("%lld\n", dp[n]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}