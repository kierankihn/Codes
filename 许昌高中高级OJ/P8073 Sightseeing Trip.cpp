#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 300 + 5;
    const int INF = 0x3f3f3f3f;
    int n, m;
    LL ans = INF;
    int pre[MAXN][MAXN];
    std::vector<int> path;
    int dis[MAXN][MAXN], mp[MAXN][MAXN];
    void getPath(int x, int y)
    {
        if (pre[x][y] == 0)
        {
            return;
        }
        getPath(x, pre[x][y]);
        path.push_back(pre[x][y]);
        getPath(pre[x][y], y);
    }
    int main()
    {
        std::memset(mp, 0x3f, sizeof(mp)), std::memset(dis, 0x3f, sizeof(dis));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            mp[i][i] = dis[i][i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            mp[u][v] = std::min(mp[u][v], d), mp[v][u] = std::min(mp[v][u], d);
            dis[u][v] = std::min(dis[u][v], d), dis[v][u] = std::min(dis[v][u], d);
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i < k; i++)
            {
                for (int j = 1; j < i; j++)
                {
                    if ((LL)dis[i][j] + mp[j][k] + mp[k][i] < ans)
                    {
                        ans = dis[i][j] + mp[j][k] + mp[k][i];
                        path.clear();
                        path.push_back(i);
                        getPath(i, j);
                        path.push_back(j);
                        path.push_back(k);
                    }
                }
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (dis[i][k] + dis[k][j] < dis[i][j])
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                        pre[i][j] = k;
                    }
                }
            }
        }
        if (path.empty())
        {
            puts("No solution.");
        }
        else
        {
            for (auto &i : path)
            {
                printf("%d ", i);
            }
            printf("\n");
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}