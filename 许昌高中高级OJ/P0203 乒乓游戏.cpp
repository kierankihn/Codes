#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    const int MAXV = 1e6 + 5;
    int n;
    LL ans = 0;
    LL a[MAXN];
    LL sum[MAXV];
    LL less[2][MAXN], more[2][MAXN];
    int lowbit(int x)
    {
        return x & (-x);
    }
    void update(LL x, LL v)
    {
        while (x < MAXV)
        {
            sum[x] += v;
            x += lowbit(x);
        }
    }
    LL query(LL x)
    {
        LL res = 0;
        while (x > 0)
        {
            res += sum[x];
            x -= lowbit(x);
        }
        return res;
    }
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
        }
        std::memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++)
        {
            less[0][i] = query(a[i]);
            more[0][i] = query(MAXV - 1) - query(a[i]);
            update(a[i], 1);
        }
        std::memset(sum, 0, sizeof(sum));
        for (int i = n; i >= 1; i--)
        {
            less[1][i] = query(a[i]);
            more[1][i] = query(MAXV - 1) - query(a[i]);
            update(a[i], 1);
        }
        for (int i = 1; i <= n; i++)
        {
            ans += less[0][i] * more[1][i] + less[1][i] * more[0][i];
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