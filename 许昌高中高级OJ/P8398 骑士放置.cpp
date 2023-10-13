#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 100 + 5;
    const int MAXV = 1e5 + 5;
    const int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
    const int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
    int n, m, k;
    int ans = 0;
    bool mark[MAXN][MAXN];
    std::vector<int> e[MAXV];
    bool vis[MAXV];
    int match[MAXV];
    void build()
    {
        for (int x = 1; x <= n; x++)
        {
            for (int y = 1; y <= m; y++)
            {
                if (mark[x][y] == true)
                {
                    continue;
                }
                for (int i = 0; i < 8; i++)
                {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (1 <= nx && nx <= n && 1 <= ny && ny <= m)
                    {
                        if (mark[nx][ny] == false)
                        {
                            e[(x - 1) * m + y].push_back((nx - 1) * m + ny);
                        }
                    }
                }
            }
        }
    }
    bool dfs(int u)
    {
        for (auto &v : e[u])
        {
            if (vis[v] == false)
            {
                vis[v] = true;
                if (match[v] == 0 || dfs(match[v]))
                {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    int main()
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= k; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            mark[u][v] = true;
        }
        build();
        ans = n * m - k;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int id = (i - 1) * m + j;
                if (((i + j) & 1) == 0 && mark[i][j] == false)
                {
                    std::memset(vis, 0, sizeof(vis));
                    if (dfs(id))
                    {
                        ans--;
                    }
                }
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