#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 12 + 5;
    const int MAX2N = (1 << 12) + 5;
    LL n, m;
    LL dp[MAXN][MAX2N];
    bool check(int x, int y)
    {
        if ((x & y) != 0)
        {
            return false;
        }
        int tmp = (x | y) | (1 << m), last = -1, now = 0;
        while (tmp)
        {
            if ((tmp & 1) == 1)
            {
                if (((now - last - 1) & 1) != 0)
                {
                    return false;
                }
                last = now;
            }
            tmp = tmp >> 1, now++;
        }
        return true;
    }
    int main()
    {
        while (scanf("%lld%lld", &n, &m) != EOF && n != 0 && m != 0)
        {
            std::memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j < (1 << m); j++)
                {
                    for (int k = 0; k < (1 << m); k++)
                    {
                        if (check(j, k))
                        {
                            dp[i][j] += dp[i - 1][k];
                        }
                    }
                }
            }
            printf("%lld\n", dp[n][0]);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}