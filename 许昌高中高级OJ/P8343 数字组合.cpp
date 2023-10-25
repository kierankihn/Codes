#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e2 + 5;
    const int MAXM = 1e4 + 5;
    int n, m;
    int val[MAXN];
    int dp[MAXM];
    int main()
    {
        dp[0] = 1;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &val[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= val[i]; j--)
            {
                dp[j] += dp[j - val[i]];
            }
        }
        printf("%d\n", dp[m]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}