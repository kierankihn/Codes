#include <bits/stdc++.h>
using namespace std;
namespace solution
{
    const int MAXN = 1e5 + 5;
    const int LOGMAXN = 30;
    int n;
    int ans;
    int val[MAXN];
    int dp[LOGMAXN];
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &val[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            int tmp = val[i], tot = 0, res = 1;
            while (tmp)
            {
                ++tot;
                if (tmp & 1)
                {
                    res = max(res, dp[tot] + 1);
                }
                tmp >>= 1;
            }
            tmp = val[i], tot = 0;
            while (tmp)
            {
                ++tot;
                if (tmp & 1)
                {
                    dp[tot] = max(dp[tot], res);
                }
                tmp >>= 1;
            }
        }
        for (int i = 1; i < 30; i++)
        {
            ans = max(ans, dp[i]);
        }
        printf("%d", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}