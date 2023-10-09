#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 100 + 5;
    using std::printf;
    using std::scanf;
    int n, m;
    LL dis[MAXN][MAXN];
    LL cnt[MAXN][MAXN];
    int main()
    {
        std::memset(dis, 0x3f, sizeof(dis));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            dis[i][i] = 0, cnt[i][i] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            LL u, v, d;
            scanf("%lld%lld%lld", &u, &v, &d);
            dis[u][v] = dis[v][u] = d;
            cnt[u][v] = cnt[v][u] = 1;
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == k || k == j || i == j)
                    {
                        continue;
                    }
                    if (dis[i][k] + dis[k][j] < dis[i][j])
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                        cnt[i][j] = cnt[i][k] * cnt[k][j];
                    }
                    else if (dis[i][k] + dis[k][j] == dis[i][j])
                    {
                        cnt[i][j] += cnt[i][k] * cnt[k][j];
                    }
                }
            }
        }
        for (int k = 1; k <= n; k++)
        {
            double res = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == k || j == k)
                    {
                        continue;
                    }
                    if (dis[i][k] + dis[k][j] == dis[i][j])
                    {
                        res += (double)cnt[i][k] * cnt[k][j] / cnt[i][j];
                    }
                }
            }
            printf("%.3lf\n", res);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}