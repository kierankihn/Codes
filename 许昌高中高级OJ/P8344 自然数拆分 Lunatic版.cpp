#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 4000 + 5;
    const LL MOD = 2147483648;
    int n;
    LL dp[MAXN];
    int main()
    {
        dp[0] = 1;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                dp[j] += dp[j - i], dp[j] %= MOD;
            }
        }
        printf("%lld\n", dp[n] - 1);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}