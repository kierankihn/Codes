#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    const int MAXH = 100 + 5;
    const LL INF = 0x3f3f3f3f3f3f3f3fLL;
    LL n, c;
    LL maxh = 0;
    LL ans = INF;
    LL a[MAXN];
    LL dp[MAXN][MAXH];
    int main()
    {
        std::memset(dp, 0x3f, sizeof(dp));
        scanf("%lld%lld", &n, &c);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            maxh = std::max(maxh, a[i]);
        }
        for (int i = a[1]; i <= maxh; i++)
        {
            dp[1][i] = (i - a[1]) * (i - a[1]);
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = a[i]; j <= maxh; j++)
            {
                for (int k = a[i - 1]; k <= maxh; k++)
                {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][k] + std ::abs(j - k) * c + (j - a[i]) * (j - a[i]));
                }
            }
        }
        for (int i = a[n]; i <= maxh; i++)
        {
            ans = std::min(ans, dp[n][i]);
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