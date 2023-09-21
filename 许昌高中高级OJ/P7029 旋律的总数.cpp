#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MOD = 1e9 + 7;
    int t;
    int n, m;
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
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
        scanf("%d", &t);
        while (t--)
        {
            scanf("%d%d", &n, &m);
            printf("%lld\n", qpow(m, n - 1, MOD));
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}