#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e4 + 5;
    const int MAXPOS = 5000 + 5;
    int n, r;
    int ans = 0;
    int val[MAXPOS][MAXPOS];
    int sum[MAXPOS][MAXPOS];
    int main()
    {
        scanf("%d%d", &n, &r);
        for (int i = 1; i <= n; i++)
        {
            int x, y, v;
            scanf("%d%d%d", &x, &y, &v);
            val[x + 1][y + 1] = v;
        }
        for (int i = 1; i <= 5001; i++)
        {
            for (int j = 1; j <= 5001; j++)
            {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + val[i][j];
            }
        }
        for (int i = r; i <= 5001; i++)
        {
            for (int j = r; j <= 5001; j++)
            {
                ans = std::max(ans, sum[i][j] - sum[i - r][j] - sum[i][j - r] + sum[i - r][j - r]);
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