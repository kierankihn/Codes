#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 3000 + 5;
    int n;
    int ans = 0;
    int max[MAXN];
    int dp[MAXN];
    int s1[MAXN], s2[MAXN];
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &s1[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &s2[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            int val = 0;
            for (int j = 1; j <= n; j++)
            {
                if (s1[i] == s2[j])
                {
                    dp[j] = std::max(dp[j], val + 1);
                }
                if (s2[j] < s1[i])
                {
                    val = std::max(val, dp[j]);
                }
                ans = std::max(ans, dp[j]);
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