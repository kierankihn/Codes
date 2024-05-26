#include <bits/stdc++.h>
namespace solution
{
    typedef char chr;
    typedef long long i64;
    const int MAXN = 2000 + 5;
    int n, m;
    int ans = 0;
    chr mp[MAXN][MAXN];
    int mpv[MAXN][MAXN];
    int mpx[MAXN][MAXN];
    int max[MAXN][MAXN];
    struct Node
    {
        int h, len;
    };
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", mp[i] + 1);
            for (int j = 1; j <= m; j++)
            {
                if (mp[i][j] == '#')
                {
                    mpv[i][j] = 1;
                }
                if (mp[i][j] == '.')
                {
                    mpv[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                mpx[i][j] = !(mpv[i][j] ^ mpv[i + 1][j] ^ mpv[i][j + 1] ^ mpv[i + 1][j + 1]);
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (mpx[i][j] == 1)
                {
                    max[i][j] = max[i - 1][j] + 1;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            std::stack<Node> stk;
            for (int j = 1; j < m + 1; j++)
            {
                Node now = {max[i][j], 0};
                while (!stk.empty() && stk.top().h >= max[i][j])
                {
                    now.len += stk.top().len, ans = std::max(ans, (now.len + 1) * (stk.top().h + 1)), stk.pop();
                }
                now.len++, stk.push(now);
            }
        }
        ans = std::max({ans, n, m});
        printf("%d\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}