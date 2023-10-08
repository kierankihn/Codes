#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    const LL MOD = 998244353;
    using std::printf;
    using std::scanf;
    int n;
    LL cnt = 0;
    LL a[MAXN];
    LL ans = 0;
    bool vis[MAXN];
    std::map<LL, std::set<LL>> mp;
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
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            mp[a[i]].insert(i);
        }
        for (auto it = --mp.end(); true; it--)
        {
            LL res = 0;
            for (auto u : it->second)
            {
                while (true)
                {
                    if (vis[u] == false)
                    {
                        vis[u] = true;
                        cnt++, res++;
                    }
                    else
                    {
                        break;
                    }
                    if (u & 1)
                    {
                        break;
                    }
                    u = u >> 1;
                }
            }
            ans += qpow(2, n - cnt, MOD) * (qpow(2, res, MOD) - 1) % MOD * it->first % MOD;
            ans %= MOD;
            if (it == mp.begin())
            {
                break;
            }
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