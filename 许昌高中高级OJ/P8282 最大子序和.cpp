#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 3e5 + 5;
    const int INF = 0x3f3f3f3f;
    int n, m;
    int ans = -INF;
    int val[MAXN];
    int sum[MAXN];
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &val[i]);
            sum[i] = sum[i - 1] + val[i];
        }
        q.push(std::make_pair(0, 0));
        for (int i = 1; i <= n; i++)
        {
            auto now = q.top();
            while (now.second < i - m)
            {
                q.pop();
                now = q.top();
            }
            ans = std::max(ans, sum[i] - now.first);
            q.push(std::make_pair(sum[i], i));
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