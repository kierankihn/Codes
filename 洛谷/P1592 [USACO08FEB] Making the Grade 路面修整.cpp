#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2000 + 5;
    const int INF = 0x3f3f3f3f;
    int n, k;
    int ans = INF;
    int a[MAXN], b[MAXN];
    int dp[MAXN][MAXN];
    int solve()
    {
        int res = INF;
        std::memset(dp, 0x3f, sizeof(dp));
        dp[0][1] = 0;
        for (int i = 1; i <= n; i++)
        {
            int val = INF;
            for (int j = 1; j <= k; j++)
            {
                val = std::min(val, dp[i - 1][j]);
                dp[i][j] = std::min(dp[i][j], std::abs(a[i] - b[j]) + val);
            }
        }
        for (int i = 1; i <= k; i++)
        {
            res = std::min(res, dp[n][i]);
        }
        return res;
    }
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }

        std::sort(b + 1, b + n + 1);
        k = std::unique(b + 1, b + n + 1) - b - 1;

        ans = std::min(ans, solve());
        std::reverse(a + 1, a + n + 1);
        ans = std::min(ans, solve());

        printf("%d\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}