#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MOD = 999911659;
    const int MODD = 999911658;
    const int MAXP = 35617 + 5;
    LL n, g;
    LL fac[MAXP], inv[MAXP];
    LL val[5], a[5] = {0, 2, 3, 4679, 35617};
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
    void init(int p)
    {
        fac[0] = 1;
        for (int i = 1; i <= p; i++)
        {
            fac[i] = fac[i - 1] * i % p;
        }
        inv[p] = 0, inv[p - 1] = qpow(fac[p - 1], p - 2, p);
        for (int i = p - 2; i >= 0; i--)
        {
            inv[i] = inv[i + 1] * (i + 1) % p;
        }
    }
    LL C(LL a, LL b, LL p)
    {
        if (a < b)
        {
            return 0;
        }
        return fac[a] * inv[a - b] % p * inv[b] % p;
    }
    LL Lucas(LL a, LL b, LL p)
    {
        if (b == 0)
        {
            return 1;
        }
        return Lucas(a / p, b / p, p) * C(a % p, b % p, p) % p;
    }
    LL CRT()
    {
        LL m = 1;
        LL res = 0;
        for (int i = 1; i <= 4; i++)
        {
            m = m * a[i];
        }
        for (int i = 1; i <= 4; i++)
        {
            LL mi = m / a[i];
            res += val[i] * mi * qpow(mi, a[i] - 2, a[i]) % m;
            res %= m;
        }
        return res;
    }
    int main()
    {
        scanf("%lld%lld", &n, &g);
        if (g % MOD == 0)
        {
            printf("%lld\n", 0LL);
            return 0;
        }
        for (int k = 1; k <= 4; k++)
        {
            LL p = a[k];
            init(p);
            LL res = 0;
            for (int i = 1; i < std::sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    res += Lucas(n, i, p) % p;
                    res += Lucas(n, n / i, p) % p;
                }
            }
            if (std::floor(std::sqrt(n)) == std::ceil(std::sqrt(n)))
            {
                res += Lucas(n, std::sqrt(n), p) % p;
            }
            val[k] = res;
        }
        LL p = CRT();
        printf("%lld\n", qpow(g, p, MOD));
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}