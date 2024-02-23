#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXV = 60 + 5;
    const int MAXN = 262144 + 5;
    int n;
    int max = 0;
    int a[MAXN];
    int dp[MAXV][MAXN];
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            dp[a[i]][i] = i;
        }
        for (int i = 1; i <= 58; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dp[i][j] == 0 && dp[i - 1][j] != 0)
                {
                    dp[i][j] = dp[i - 1][dp[i - 1][j] + 1];
                }
                if (dp[i][j] != 0)
                {
                    max = std::max(max, i);
                }
            }
        }
        printf("%d\n", max);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}