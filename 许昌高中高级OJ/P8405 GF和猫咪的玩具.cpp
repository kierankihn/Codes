#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 100 + 5;
    using std::printf;
    using std::scanf;
    int n, m;
    int ans = 0;
    int dis[MAXN][MAXN];
    int main()
    {
        std::memset(dis, 0x3f, sizeof(dis));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            dis[i][i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            dis[u][v] = dis[v][u] = 1;
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ans = std::max(ans, dis[i][j]);
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