#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int INF = 0x3f3f3f3f;
    LL l;
    LL cnt = 0;
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
    LL euler(LL x)
    {
        LL res = x;
        for (LL i = 2; i <= std::sqrt(x); i++)
        {
            if (x % i == 0)
            {
                res = res * (i - 1) / i;
            }
            while (x % i == 0)
            {
                x = x / i;
            }
        }
        if (x > 1)
        {
            res = res * (x - 1) / x;
        }
        return res;
    }
    int main()
    {
        while (scanf("%lld", &l) != EOF && l != 0)
        {
            LL m = 9 * l / std::__gcd(l, 8LL);
            LL phi = euler(m);
            LL ans = INF;
            for (LL i = 1; i <= std::sqrt(phi); i++)
            {
                if (phi % i == 0)
                {
                    if (qpow(10, i, m) == 1)
                    {
                        ans = std::min(ans, i);
                        break;
                    }
                }
            }
            for (LL i = std::sqrt(phi); i >= 1; i--)
            {
                if (phi % i == 0)
                {
                    if (qpow(10, phi / i, m) == 1)
                    {
                        ans = std::min(ans, phi / i);
                        break;
                    }
                }
            }
            printf("Case %lld: %lld\n", ++cnt, ans == INF ? 0 : ans);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}