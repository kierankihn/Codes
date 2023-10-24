#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXK = 200 + 5;
    const int MAXN = 1000 + 5;
    const int INF = 0x3f3f3f3f;
    int n, k;
    int ans = INF;
    int p[MAXN];
    int cost[MAXK][MAXK];
    int dp[MAXN][MAXK][MAXK];
    int num[MAXN][MAXK][MAXK][3];
    int main()
    {
        std::memset(dp, 0x3f, sizeof(dp));
        scanf("%d%d", &k, &n);
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                scanf("%d", &cost[i][j]);
            }
        }
        dp[0][1][2] = dp[0][2][1] = 0, p[0] = 3;
        num[0][1][2][0] = 1, num[0][1][2][1] = 2, num[0][1][2][2] = 3;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &p[i]);
            for (int x = 1; x <= k; x++)
            {
                for (int y = 1; y <= k; y++)
                {
                    if (x != y && x != p[i] && y != p[i])
                    {
                        dp[i][x][y] = std::min(dp[i][x][y], dp[i - 1][x][y] + cost[p[i - 1]][p[i]]);
                    }
                    if (x != p[i - 1] && x != p[i] && p[i - 1] != p[i])
                    {
                        dp[i][x][p[i - 1]] = std::min(dp[i][x][p[i - 1]], dp[i - 1][x][y] + cost[y][p[i]]);
                    }
                    if (y != p[i - 1] && y != p[i] && p[i - 1] != p[i])
                    {
                        dp[i][y][p[i - 1]] = std::min(dp[i][y][p[i - 1]], dp[i - 1][x][y] + cost[x][p[i]]);
                    }
                }
            }
        }
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i == j || i == p[n] || j == p[n])
                {
                    continue;
                }
                ans = std::min(ans, dp[n][i][j]);
            }
        }
        printf("%d\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}