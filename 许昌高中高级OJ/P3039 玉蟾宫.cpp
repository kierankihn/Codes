#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXN = 1e3 + 5;
    int n, m;
    int ans = 0;
    char mp[MAXN][MAXN];
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
            for (int j = 1; j <= m; j++)
            {
                scanf("%s", mp[i] + j);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (mp[i][j] == 'F')
                {
                    max[i][j] = max[i - 1][j] + 1;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            std::stack<Node> s;
            for (int j = 1; j <= m + 1; j++)
            {
                Node now = {0, 0};
                while (s.empty() == false && s.top().h >= max[i][j])
                {
                    now.len += s.top().len, ans = std::max(ans, now.len * s.top().h), s.pop();
                }
                now.h = max[i][j], now.len += 1;
                s.push(now);
            }
        }
        printf("%d\n", ans * 3);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}