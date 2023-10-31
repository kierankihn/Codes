#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    int n, s;
    LL t[MAXN], c[MAXN];
    LL sumt[MAXN], sumc[MAXN];
    LL dp[MAXN];
    int main()
    {
        std::memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        scanf("%d%d", &n, &s);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld", &t[i], &c[i]);
            sumt[i] = sumt[i - 1] + t[i], sumc[i] = sumc[i - 1] + c[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] = std::min(dp[i], dp[j - 1] + sumt[i] * (sumc[i] - sumc[j - 1]) + s * (sumc[n] - sumc[j - 1]));
            }
        }
        printf("%lld\n", dp[n]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}