#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 100 + 5;
    const int MAXM = 2e5 + 5;
    int n, m;
    struct Node
    {
        int start, len, cost;
    };
    bool operator<(const Node &a, const Node &b)
    {
        return a.start < b.start;
    }
    Node node[MAXN];
    int dp[MAXN][MAXM];
    int main()
    {
        scanf("%d%d", &m, &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &node[i].len, &node[i].cost, &node[i].start);
        }
        std::sort(node + 1, node + n + 1);
        for (int i = 1; i <= n; i++)
        {
            std::deque<std::pair<int, int>> q;
            q.push_back(std::make_pair(0, 0));
            for (int j = 1; j <= m; j++)
            {
                // 不粉刷
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                // 将不合法的出队
                while (!q.empty() && q.front().second < j - node[i].len)
                {
                    q.pop_front();
                }
                if (!q.empty() && node[i].start <= j && j <= node[i].start + node[i].len - 1)
                {
                    // 更新
                    dp[i][j] = std::max(dp[i][j], q.front().first + j * node[i].cost);
                }
                if (j < node[i].start)
                {
                    while (!q.empty() && q.back().first <= dp[i - 1][j] - node[i].cost * j)
                    {
                        q.pop_back();
                    }
                    q.push_back(std::make_pair(dp[i - 1][j] - node[i].cost * j, j));
                }
            }
        }
        printf("%d\n", dp[n][m]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}