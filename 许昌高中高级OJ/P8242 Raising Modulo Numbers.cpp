#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    int t;
    int n;
    int m;
    LL ans = 0;
    LL qpow(LL a, LL b, LL c)
    {
        LL res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a % c;
            }
            a = a * a % c;
            b = b >> 1;
        }
        return res;
    }
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            ans = 0;
            scanf("%d%d", &m, &n);
            for (int i = 1; i <= n; i++)
            {
                LL a, b;
                scanf("%lld%lld", &a, &b);
                ans += qpow(a, b, m);
                ans %= m;
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