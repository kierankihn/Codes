#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 300 + 5;
    const int MOD = 1e9;
    int n;
    char s[MAXN];
    LL dp[MAXN][MAXN];
    int main()
    {
        scanf("%s", s + 1);
        n = std::strlen(s + 1);
        for (int i = 1; i <= n; i++)
        {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; len++)
        {
            for (int l = 1, r = len; r <= n; l++, r++)
            {
                for (int k = l + 1; k <= r; k++)
                {
                    if (s[l] == s[k])
                    {
                        dp[l][r] += dp[l + 1][k - 1] * dp[k][r] % MOD;
                        dp[l][r] %= MOD;
                    }
                }
            }
        }
        printf("%lld\n", dp[1][n]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}