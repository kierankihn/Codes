#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXN = 2e3 + 5;
    const int MAXA = 2e5 + 5;
    const int MOD = 1e9 + 7;
    int h, w, n;
    struct Point
    {
        int x, y;
        Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    };
    bool operator<(const Point a, const Point b)
    {
        if (a.x == b.x)
        {
            return a.y < b.y;
        }
        return a.x < b.x;
    }
    Point p[MAXN];
    i64 dp[MAXN];
    i64 fac[MAXA], inv[MAXA];
    i64 qpow(i64 a, i64 b, i64 c)
    {
        i64 res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a % c;
            }
            a = a * a % c, b = b >> 1;
        }
        return res;
    }
    void init()
    {
        fac[0] = 1, inv[0] = 1;
        for (i64 i = 1; i <= 2e5; i++)
        {
            fac[i] = i * fac[i - 1] % MOD, inv[i] = qpow(fac[i], MOD - 2, MOD);
        }
    }
    i64 C(i64 x, i64 y)
    {
        if (x < y)
        {
            return 0;
        }
        return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
    }
    int main()
    {
        init();
        scanf("%d%d%d", &h, &w, &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        std::sort(p + 1, p + n + 1);
        p[n + 1].x = h, p[n + 1].y = w;
        for (int i = 1; i <= n + 1; i++)
        {
            dp[i] = C(p[i].x + p[i].y - 2, p[i].x - 1);
            for (int j = 1; j < i; j++)
            {
                if (p[j].x <= p[i].x && p[j].y <= p[i].y)
                {
                    int x = p[i].x - p[j].x, y = p[i].y - p[j].y;
                    dp[i] -= dp[j] * C(x + y, x) % MOD;
                    dp[i] %= MOD, dp[i] += MOD, dp[i] %= MOD;
                }
            }
        }
        printf("%lld\n", dp[n + 1]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}