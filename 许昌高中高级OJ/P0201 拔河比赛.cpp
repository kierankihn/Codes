#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 500000 + 5;
    int n;
    int w = 0;
    int a[MAXN];
    int dp[MAXN];
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            w += a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = w / 2; j >= a[i]; j--)
            {
                dp[j] = std::max(dp[j], dp[j - a[i]] + a[i]);
            }
        }
        printf("%d %d\n", dp[w / 2], w - dp[w / 2]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}