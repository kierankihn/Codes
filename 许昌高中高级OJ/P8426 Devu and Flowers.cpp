#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 20 + 5;
    const int MOD = 1e9 + 7;
    LL n, m;
    LL ans = 0;
    LL a[MAXN];
    LL inv[MAXN];
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
    LL C(LL a, LL b, LL c)
    {
        if (b < 0 || a < 0 || a < b)
        {
            return 0;
        }
        a %= c;
        if (a == 0 || b == 0)
        {
            return 1;
        }
        LL res = 1;
        for (LL i = a - b + 1; i <= a; i++)
        {
            res = res * i % c;
        }
        for (int i = 1; i <= b; i++)
        {
            res = res * inv[i] % c;
        }
        return res;
    }
    int main()
    {
        for (int i = 1; i <= 20; i++)
        {
            inv[i] = qpow(i, MOD - 2, MOD);
        }
        scanf("%lld%lld", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
        }
        ans = C(n + m - 1, n - 1, MOD);
        for (LL i = 1; i < (1 << n); i++)
        {
            LL t = n + m, p = 0;
            for (LL j = 1; j <= n; j++)
            {
                if ((i >> (j - 1)) & 1)
                {
                    p++, t -= a[j];
                }
            }
            t -= p + 1;
            if (p & 1)
            {
                ans = (ans - C(t, n - 1, MOD)) % MOD;
            }
            else
            {
                ans = (ans + C(t, n - 1, MOD)) % MOD;
            }
            ans %= MOD, ans += MOD, ans %= MOD;
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