#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    LL n, k;
    LL ans = 0;
    int main()
    {
        scanf("%lld%lld", &n, &k);
        for (LL l = 1; l <= n; l++)
        {
            LL t = k / l;
            LL r = (t == 0 ? n : std::min(k / t, n));
            ans += (r - l + 1) * (l + r) * (k / l) / 2;
            l = r;
        }
        printf("%lld\n", n * k - ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}