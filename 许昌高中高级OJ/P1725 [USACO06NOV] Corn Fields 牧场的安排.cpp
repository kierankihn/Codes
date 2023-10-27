#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 12 + 5;
    const int MAX2N = (1 << 12) + 5;
    const int MOD = 1e8;
    int n, m;
    int ans = 0;
    int p[MAXN];
    int a[MAXN][MAXN];
    int dp[MAXN][MAX2N];
    bool check(int x)
    {
        bool flag = false;
        while (x)
        {
            if (x & 1)
            {
                if (flag)
                {
                    return false;
                }
                flag = true;
            }
            else
            {
                flag = false;
            }
            x = x >> 1;
        }
        return true;
    }
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
                p[i] = (p[i] << 1) | a[i][j];
            }
        }
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < (1 << m); j++)
            {
                for (int k = 0; k < (1 << m); k++)
                {
                    if (((j & (~p[i])) == 0) && check(j) && (j & k) == 0)
                    {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                    }
                }
            }
        }
        for (int i = 0; i < (1 << m); i++)
        {
            ans = (ans + dp[n][i]) % MOD;
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