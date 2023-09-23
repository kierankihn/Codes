#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 5e7 + 5;
    const int MAXLOGN = 1000 + 5;
    const int MOD = 9901;
    LL n, m;
    LL ans = 1;
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
    LL div[MAXLOGN], cnt[MAXLOGN];
    void divide(LL x)
    {
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                div[++div[0]] = i;
            }
            while (x % i == 0)
            {
                cnt[div[0]]++, x = x / i;
            }
        }
        if (x > 1)
        {
            div[++div[0]] = x, cnt[div[0]] = 1;
        }
    }
    LL count(LL a1, LL x, LL d)
    {
        LL an = a1 * qpow(d, x, MOD);
        return (((an - a1) % MOD) + MOD) % MOD * qpow(d - 1, MOD - 2, MOD) % MOD;
    }
    int main()
    {
        scanf("%lld%lld", &n, &m);
        divide(n);
        for (int i = 1; i <= div[0]; i++)
        {
            if ((div[i] - 1) % MOD == 0)
            {
                ans *= (cnt[i] * m + 1) % MOD;
            }
            else
            {
                ans *= count(1, cnt[i] * m + 1, div[i]) % MOD;
            }
            ans %= MOD;
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