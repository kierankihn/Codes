#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    bool fail = false;
    LL n;
    LL x0, m0;
    LL a[MAXN], m[MAXN];
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
        while (scanf("%lld", &n) != EOF)
        {
            fail = false;
            for (int i = 1; i <= n; i++)
            {
                scanf("%lld%lld", &m[i], &a[i]);
            }
            x0 = a[1], m0 = m[1];
            x0 %= m0, x0 += m0, x0 %= m0;
            for (int i = 2; i <= n; i++)
            {
                LL x, y;
                LL d = exgcd(m0, m[i], x, y);
                a[i] -= x0, a[i] %= m[i], a[i] += m[i], a[i] %= m[i];
                if (a[i] % d == 0)
                {
                    x0 = x0 + x * (a[i] / d) * m0, m0 = m0 * m[i] / d;
                    x0 %= m0, x0 += m0, x0 %= m0;
                }
                else
                {
                    fail = true;
                    break;
                }
            }
            printf("%lld\n", fail ? -1LL : x0);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}