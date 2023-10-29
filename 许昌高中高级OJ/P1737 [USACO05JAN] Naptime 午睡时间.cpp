#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 4000 + 5;
    int n, m;
    LL ans = 0;
    LL v[MAXN];
    LL dp[MAXN][2];
    void solve()
    {
        for (int i = 2; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                dp[j][0] = std::max(dp[j][0], dp[j][1]);
                dp[j][1] = std::max(dp[j - 1][0], dp[j - 1][1] + v[i]);
            }
        }
    }
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &v[i]);
        }

        std::memset(dp, 0xcf, sizeof(dp));
        dp[0][0] = 0, dp[1][1] = 0;
        solve();
        ans = std::max({ans, dp[m][0], dp[m][1]});

        std::memset(dp, 0xcf, sizeof(dp));
        dp[0][0] = 0, dp[1][1] = v[1];
        solve();
        ans = std::max({ans, dp[m][1]});

        printf("%lld\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}