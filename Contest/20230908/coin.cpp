#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e5 + 5;
    LL ans = 0, p1 = 0, p2 = 0;
    LL n;
    struct Node
    {
        LL x, y;
    };
    bool operator<(const Node a, const Node b)
    {
        return a.x < b.x;
    }
    Node node[MAXN];
    LL cnt[MAXN][3];
    int main()
    {
        // freopen("coin.in", "r", stdin);
        // freopen("coin.out", "w", stdout);
        scanf("%lld", &n);
        for (int i = 1; i <= 2 * n; i++)
        {
            scanf("%lld%lld", &node[i].x, &node[i].y);
        }
        for (int i = 1; i <= 2 * n; i++)
        {
            if (node[i].y < 1)
            {
                ans += 1 - node[i].y, node[i].y = 1;
            }
            if (node[i].y > 2)
            {
                ans += node[i].y - 2, node[i].y = 2;
            }
            if (node[i].x < 1)
            {
                ans += 1 - node[i].x, node[i].x = 1;
            }
            if (node[i].x > n)
            {
                ans += node[i].x - n, node[i].x = n;
            }
            cnt[node[i].x][node[i].y]++;
        }
        for (int i = 1; i <= n; i++)
        {
            p1 += cnt[i][1] - 1, p2 += cnt[i][2] - 1;
            while (p1 > 0 && p2 < 0)
            {
                p1--, p2++, ans++;
            }
            while (p1 < 0 && p2 > 0)
            {
                p1++, p2--, ans++;
            }
            ans += std::abs(p1) + std::abs(p2);
        }
        printf("%lld\n", ans);
        return 0;
    }
} // namespace solution
int main()
{
    solution::main();
    return 0;
}