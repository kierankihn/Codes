#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    using std::printf;
    using std::scanf;
    int t;
    LL n, p;
    LL cnt = 0;
    LL ans = 0;
    std::pair<LL, LL> cost[MAXN];
    int main()
    {
        freopen("1.in", "r", stdin);
        scanf("%d", &t);
        while (t--)
        {
            scanf("%lld%lld", &n, &p);
            for (int i = 1; i <= n; i++)
            {
                scanf("%lld", &cost[i].second);
            }
            for (int i = 1; i <= n; i++)
            {
                scanf("%lld", &cost[i].first);
            }
            std::sort(cost + 1, cost + n + 1);
            cnt = 1, ans = p;
            for (int i = 1; i <= n; i++)
            {
                auto &u = cost[i];
                if (u.first >= p)
                {
                    ans += (n - cnt) * p, cnt = n;
                }
                if (u.second >= n - cnt)
                {
                    ans += (n - cnt) * u.first, cnt = n;
                    break;
                }
                else
                {
                    ans += u.second * u.first, cnt += u.second;
                }
            }
            ans += (n - cnt) * p;
            printf("%lld\n", ans);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}