#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    const int MAXLOGN = 20 + 5;
    const LL INF = 0x3f3f3f3f;
    LL n, m, q;
    LL a[MAXN], b[MAXN];
    LL suma[MAXN], sumb[MAXN];
    LL mina[MAXN][MAXLOGN], minb[MAXN][MAXLOGN];
    LL maxa[MAXN][MAXLOGN], maxb[MAXN][MAXLOGN];
    LL posmin[MAXN][MAXLOGN], negmax[MAXN][MAXLOGN];
    void build(LL val[], LL node[][MAXLOGN], std::function<LL(LL, LL)> cmp, std::function<bool(LL)> f, LL x)
    {
        for (int i = 1; i <= n; i++)
        {
            node[i][0] = f(val[i]) ? val[i] : x;
        }
        for (int k = 1; k <= std::__lg(n); k++)
        {
            for (int i = 1; i + (1 << k) - 1 <= n; i++)
            {
                node[i][k] = cmp(node[i][k - 1], node[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    LL query(LL node[][MAXLOGN], std::function<LL(LL, LL)> cmp, LL l, LL r)
    {
        LL k = std::__lg(r - l + 1);
        return cmp(node[l][k], node[r - (1 << k) + 1][k]);
    }
    auto min = [](LL a, LL b)
    {
        return std::min(a, b);
    };
    auto max = [](LL a, LL b)
    {
        return std::max(a, b);
    };
    auto check = [](LL x)
    {
        return true;
    };
    auto checkneg = [](LL x)
    {
        return x < 0;
    };
    auto checkpos = [](LL x)
    {
        return x > 0;
    };
    int main()
    {
        scanf("%lld%lld%lld", &n, &m, &q);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            suma[i] = suma[i - 1] + (a[i] == 0);
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%lld", &b[i]);
            sumb[i] = sumb[i - 1] + (b[i] == 0);
        }
        build(a, mina, min, check, INF);
        build(b, minb, min, check, INF);
        build(a, maxa, max, check, -INF);
        build(b, maxb, max, check, -INF);
        build(a, posmin, min, checkpos, INF);
        build(a, negmax, max, checkneg, -INF);
        for (int i = 1; i <= q; i++)
        {
            LL l1, r1, l2, r2;
            LL ans = -INF * INF;
            scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
            ans = std::max(ans, std::min({query(mina, min, l1, r1) * query(minb, min, l2, r2),
                                          query(mina, min, l1, r1) * query(maxb, max, l2, r2),
                                          ((sumb[r2] - sumb[l2 - 1] != 0) ? 0 : (INF * INF))}));
            ans = std::max(ans, std::min({query(maxa, max, l1, r1) * query(minb, min, l2, r2),
                                          query(maxa, max, l1, r1) * query(maxb, max, l2, r2),
                                          ((sumb[r2] - sumb[l2 - 1] != 0) ? 0 : (INF * INF))}));
            if (query(posmin, min, l1, r1) != INF)
            {
                ans = std::max(ans, std::min({query(posmin, min, l1, r1) * query(minb, min, l2, r2),
                                              query(posmin, min, l1, r1) * query(maxb, max, l2, r2),
                                              ((sumb[r2] - sumb[l2 - 1] != 0) ? 0 : (INF * INF))}));
            }
            if (query(negmax, max, l1, r1) != -INF)
            {
                ans = std::max(ans, std::min({query(negmax, max, l1, r1) * query(minb, min, l2, r2),
                                              query(negmax, max, l1, r1) * query(maxb, max, l2, r2),
                                              ((sumb[r2] - sumb[l2 - 1] != 0) ? 0 : (INF * INF))}));
            }
            ans = std::max(ans, ((suma[r1] - suma[l1 - 1] != 0) ? 0 : (-INF * INF)));
            printf("%lld\n", ans);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}