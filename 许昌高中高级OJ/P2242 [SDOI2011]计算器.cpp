#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    int n, k;
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
    LL BSGS(LL a, LL b, LL p)
    {
        std::unordered_map<LL, LL> mp;
        mp.clear();
        LL m = std::sqrt(p) + 1;
        LL cur = 1;
        for (LL i = 1; i <= m; i++)
        {
            cur = cur * a % p;
            mp[b * cur % p] = i;
        }
        LL a_t = cur;
        for (LL i = 1; i <= m; i++)
        {
            auto it = mp.find(cur);
            if (it != mp.end())
            {
                return i * m - it->second;
            }
            cur = cur * a_t % p;
        }
        return -1;
    }
    int main()
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            LL a, b, p;
            scanf("%lld%lld%lld", &a, &b, &p);
            if (k == 1)
            {
                printf("%lld\n", qpow(a, b, p));
            }
            if (k == 2)
            {
                LL x = 0, y = 0;
                LL d = exgcd(a, p, x, y);
                if (b % d == 0)
                {
                    printf("%lld\n", (((x * b / d) % p) + p) % p);
                }
                else
                {
                    puts("Orz, I cannot find x!");
                }
            }
            if (k == 3)
            {
                LL res;
                if (a % p == 0)
                {
                    b %= p;
                    if (b == 0)
                    {
                        res = 1;
                    }
                    if (b == 1)
                    {
                        res = 0;
                    }
                    if (b != 1 && b != 0)
                    {
                        res = -1;
                    }
                }
                else
                {
                    res = BSGS(a, b, p);
                }
                if (res != -1)
                {
                    printf("%lld\n", res);
                }
                else
                {
                    puts("Orz, I cannot find x!");
                }
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}