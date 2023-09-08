#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    int n, m;
    int ans[MAXN];
    std::priority_queue<int, std::vector<int>, std::greater<int>> ball;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> kid;
    int main()
    {
        freopen("balloon.in", "r", stdin);
        freopen("balloon.out", "w", stdout);
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            kid.push(std::make_pair(tmp, i));
        }
        for (int  i = 1; i <= m; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            ball.push(tmp);
        }
        while (!kid.empty())
        {
            auto u = kid.top();
            kid.pop();
            while (!ball.empty() && u.first >= ball.top())
            {
                ball.pop();
                ans[u.second]++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d\n", ans[i]);
        }
        return 0;
    }
} // namespace solution
int main()
{
    solution::main();
    return 0;
}