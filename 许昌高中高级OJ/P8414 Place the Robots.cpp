#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 5000 + 5;
    int t;
    int c;
    int n, m;
    char mp[MAXN][MAXN];
    std::vector<int> e[MAXN];
    bool vis[MAXN];
    int match[MAXN];
    int line[MAXN][MAXN], col[MAXN][MAXN];
    void init()
    {
        std::memset(col, 0, sizeof(col));
        std::memset(line, 0, sizeof(line));
        std::memset(match, 0, sizeof(match));
        for (auto &i : e)
        {
            i.clear();
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
    int solve()
    {
        int res = 0;
        for (int i = 1; i <= line[n][m]; i++)
        {
            std::memset(vis, 0, sizeof(vis));
            if (dfs(i))
            {
                res++;
            }
        }
        return res;
    }
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            init();
            scanf("%d%d", &n, &m);
            for (int i = 1; i <= n; i++)
            {
                scanf("%s", mp[i] + 1);
            }
            col[n][0] = line[0][m] = 0;
            for (int i = 1; i <= n; i++)
            {
                line[i][0] = line[i - 1][m] + 1;
                for (int j = 1; j <= m; j++)
                {
                    line[i][j] = line[i][j - 1];
                    if (mp[i][j] == '#')
                    {
                        line[i][j]++;
                    }
                }
            }
            for (int i = 1; i <= m; i++)
            {
                col[0][i] = col[n][i - 1] + 1;
                for (int j = 1; j <= n; j++)
                {
                    col[j][i] = col[j - 1][i];
                    if (mp[j][i] == '#')
                    {
                        col[j][i]++;
                    }
                }
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (mp[i][j] == 'o')
                    {
                        e[line[i][j]].push_back(col[i][j]);
                    }
                }
            }
            printf("Case :%d\n", ++c);
            printf("%d\n", solve());
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}