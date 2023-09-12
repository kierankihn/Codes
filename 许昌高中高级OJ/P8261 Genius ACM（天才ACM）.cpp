#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 5e5 + 5;
    int t;
    LL n, m, k;
    LL ans = 0;
    LL val[MAXN];
    LL a[MAXN], b[MAXN];
    void sort(int l, int r, int p)
    {
        for (int i = r + 1; i <= r + p; i++)
        {
            a[i] = val[i];
        }
        std::sort(a + r + 1, a + r + p + 1);
        int p1 = l, p2 = r + 1;
        for (int i = l; i <= r + p; i++)
        {
            if (p1 > r || (p2 <= r + p && val[p1] > a[p2]))
            {
                b[i] = a[p2++];
            }
            else
            {
                b[i] = val[p1++];
            }
        }
    }
    LL getsum(int l, int r)
    {
        LL res = 0;
        int i = l, j = r;
        int cnt = 0;
        while (i < j && ++cnt <= m)
        {
            res += (LL)(b[i] - b[j]) * (b[i] - b[j]);
            i++, j--;
        }
        return res;
    }
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            ans = 0;
            scanf("%lld%lld%lld", &n, &m, &k);
            for (int i = 1; i <= n; i++)
            {
                scanf("%lld", &val[i]);
            }
            LL l = 0, r = 0, p = 1;
            while (r < n)
            {
                l = ++r, p = 1;
                while (p > 0)
                {
                    sort(l, r, p);
                    // printf("ziii %lld %lld %lld %lld\n", l, r, p, getsum(l, r + p));
                    // for (int i = 1; i <= n; i++)
                    // {
                    //     printf("%lld ", val[i]);
                    // }
                    // printf("\n");
                    // for (int i = 1; i <= n; i++)
                    // {
                    //     printf("%lld ", b[i]);
                    // }
                    // printf("\n");
                    if (getsum(l, r + p) <= k)
                    {
                        for (int i = l; i <= r + p; i++)
                        {
                            val[i] = b[i];
                        }
                        r += p, p = std::min(p << 1LL, n - r);
                    }
                    else
                    {
                        p = p >> 1;
                    }
                }
                ans++;
            }
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