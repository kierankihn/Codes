#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXN = 1e5 + 5;
    const int MAXLOGN = 20 + 5;
    const i64 INF = 0x3f3f3f3f3f3f3f3fLL;
    int n;
    i64 ans = 0;
    i64 a[MAXN], sum[MAXN], min[MAXN][MAXLOGN];
    void build()
    {
        for (int i = 0; i <= n; i++)
        {
            min[i][0] = a[i];
        }
        for (int k = 1; k <= std::__lg(n + 1); k++)
        {
            for (int l = 0, r = (1 << k) - 1; r <= n; l++, r++)
            {
                min[l][k] = std::min(min[l][k - 1], min[l + (1 << (k - 1))][k - 1]);
            }
        }
    }
    i64 query(int l, int r)
    {
        if (r < l)
        {
            return INF;
        }
        int k = std::__lg(r - l + 1);
        return std::min(min[l][k], min[r - (1 << k) + 1][k]);
    }
    int findLeft(int x)
    {
        int l = 1, r = x;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (query(mid, x - 1) < a[x])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
    int findRight(int x)
    {
        int l = x + 1, r = n + 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (query(x + 1, mid) > a[x])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l - 1;
    }
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        build();
        for (int i = 1; i <= n; i++)
        {
            int l = findLeft(i), r = findRight(i);
            ans = std::max(ans, (sum[r] - sum[l - 1]) * a[i]);
        }
        printf("%lld\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}