#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 50 + 5;
    const int INF = 0x3f3f3f3f;
    int n;
    int ans = 0;
    int val[MAXN * 2];
    char tag[MAXN * 2];
    int dp[2][MAXN * 2][MAXN * 2];
    int get(int a, int b, char c)
    {
        if (c == 't')
        {
            return a + b;
        }
        if (c == 'x')
        {
            return a * b;
        }
        return -1;
    }
    int main()
    {
        scanf("%d", &n);
        for (int l = 1; l <= 2 * n; l++)
        {
            for (int r = l; r <= 2 * n; r++)
            {
                dp[0][l][r] = INF, dp[1][l][r] = -INF;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            char s[MAXN];
            scanf("%s%d", s, &val[i]);
            tag[i + n] = tag[i] = s[0], val[i + n] = val[i];
            dp[0][i][i] = dp[1][i][i] = val[i] = dp[0][i + n][i + n] = dp[1][i + n][i + n] = val[i];
        }
        for (int len = 2; len <= n; len++)
        {
            for (int l = 1, r = len; r <= 2 * n; l++, r++)
            {
                for (int k = l; k < r; k++)
                {
                    dp[0][l][r] = std::min({dp[0][l][r],
                                            get(dp[0][l][k], dp[0][k + 1][r], tag[k + 1]),
                                            get(dp[0][l][k], dp[1][k + 1][r], tag[k + 1]),
                                            get(dp[1][l][k], dp[0][k + 1][r], tag[k + 1])});
                    dp[1][l][r] = std::max({dp[1][l][r],
                                            get(dp[0][l][k], dp[0][k + 1][r], tag[k + 1]),
                                            get(dp[1][l][k], dp[1][k + 1][r], tag[k + 1])});
                }
            }
        }
        for (int l = 1, r = l + n - 1; l <= n; l++, r++)
        {
            ans = std::max(ans, dp[1][l][r]);
        }
        printf("%d\n", ans);
        for (int l = 1, r = l + n - 1; l <= n; l++, r++)
        {
            if (dp[1][l][r] == ans)
            {
                printf("%d ", l);
            }
        }
        printf("\n");
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}