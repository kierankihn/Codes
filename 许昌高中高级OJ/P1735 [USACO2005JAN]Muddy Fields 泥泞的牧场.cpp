#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 50 + 5;
    const int MAXV = 1e6 + 5;
    int n, m;
    int ans = 0;
    char mp[MAXN][MAXN];
    int ln[MAXN][MAXN], cl[MAXN][MAXN];
    bool vis[MAXV];
    int match[MAXV];
    std::vector<int> e[MAXV];
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
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", mp[i] + 1);
        }
        for (int i = 1; i <= n; i++)
        {
            ln[i][0] = ln[i - 1][m];
            for (int j = 1; j <= m; j++)
            {
                if (mp[i][j] == '*')
                {
                    if (j == 1 || mp[i][j - 1] == '.')
                    {
                        ln[i][j] = ln[i][j - 1] + 1;
                        continue;
                    }
                }
                ln[i][j] = ln[i][j - 1];
            }
        }
        for (int i = 1; i <= m; i++)
        {
            cl[0][i] = cl[n][i - 1];
            for (int j = 1; j <= n; j++)
            {
                if (mp[j][i] == '*')
                {
                    if (j == 1 || mp[j - 1][i] == '.')
                    {
                        cl[j][i] = cl[j - 1][i] + 1;
                        continue;
                    }
                }
                cl[j][i] = cl[j - 1][i];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (mp[i][j] == '*')
                {
                    e[ln[i][j]].push_back(cl[i][j]);
                }
            }
        }
        for (int i = 1; i <= ln[n][m]; i++)
        {
            std::memset(vis, 0, sizeof(vis));
            if (dfs(i))
            {
                ans++;
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