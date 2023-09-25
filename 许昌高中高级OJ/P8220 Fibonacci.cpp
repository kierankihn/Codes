#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 10 + 5;
    LL n;
    LL x0, m0;
    LL a[MAXN], b[MAXN];
    LL exgcd(LL a, LL b, LL &x, LL &y)
    {
        if (b == 0)
        {
            x = 1, y = 0;
            return a;
        }
        LL d = exgcd(b, a % b, x, y);
        LL z = x;
        x = y, y = z - (a / b) * y;
        return d;
    }
    int main()
    {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld", &a[i], &b[i]);
        }
        x0 = b[1] % a[1], m0 = a[1];
        for (int i = 2; i <= n; i++)
        {
            LL x, y, d;
            d = exgcd(m0, a[i], x, y);
            b[i] -= x0, b[i] %= a[i], b[i] += a[i], b[i] %= a[i];
            if (b[i] % d == 0)
            {
                x0 = x0 + x * m0 * (b[i] / d);
                m0 = m0 * a[i] / d;
                x0 %= m0, x0 += m0, x0 %= m0;
            }
        }
        printf("%lld\n", x0);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}