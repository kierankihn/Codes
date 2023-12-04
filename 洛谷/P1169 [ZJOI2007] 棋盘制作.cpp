#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXN = 2e3 + 5;
    int n, m;
    int ans1, ans2;
    int mp[MAXN][MAXN];
    int max[MAXN][MAXN];
    struct Node
    {
        int h, len;
    };
    int main()
    {
        std::fill(mp[0], mp[0] + MAXN * MAXN, -1);
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &mp[i][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (mp[i][j] != mp[i - 1][j])
                {
                    max[i][j] = max[i - 1][j];
                }
                max[i][j]++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            std::stack<Node> s;
            for (int j = 1; j <= m + 1; j++)
            {
                Node now = {0, 0};
                while (s.empty() == false && (s.top().h >= max[i][j] || mp[i][j] == mp[i][j - 1]))
                {
                    now.len += s.top().len, ans1 = std::max(ans1, std::min(now.len, s.top().h) * std::min(now.len, s.top().h)), ans2 = std::max(ans2, now.len * s.top().h), s.pop();
                }
                if (mp[i][j] == mp[i][j - 1])
                {
                    now.len = 0;
                }
                now.h = max[i][j], now.len += 1;
                s.push(now);
            }
        }
        printf("%d\n", ans1);
        printf("%d\n", ans2);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}