#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e5 + 5;
    LL n, q;
    LL now, L, R, tot;
    LL a[MAXN], w[MAXN], ans[MAXN];
    struct Node
    {
        LL val, pos;
        Node(LL _val = 0, LL _pos = 0) : val(_val), pos(_pos) {}
    };
    bool operator<(const Node &a, const Node &b)
    {
        return a.val < b.val;
    }
    Node node[MAXN];
    int main()
    {
        scanf("%lld%lld", &n, &q);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            node[i].val = a[i + 1] - a[i], node[i].pos = i;
        }
        tot = 1;
        std::sort(node + 1, node + n);
        for (int i = 1; i <= q; i++)
        {
            scanf("%lld", &w[i]);
            now += w[i], L = std::max(L, -now), R = std::max(R, now);
            while (L + R >= node[tot].val && tot < n)
            {
                if (w[i] < 0)
                {
                    ans[node[tot].pos] += R;
                    ans[node[tot].pos + 1] += a[node[tot].pos + 1] - (a[node[tot].pos] + R);
                }
                if (w[i] > 0)
                {
                    ans[node[tot].pos + 1] += L;
                    ans[node[tot].pos] += a[node[tot].pos + 1] - L - a[node[tot].pos];
                }
                tot++;
            }
            // printf("pos: %lld, L: %lld, R: %lld\n", now, L, R);
            // for (int j = 1; j <= n; j++)
            // {
            //     printf("%lld%c", ans[j], j == n ? '\n' : ' ');
            // }
        }
        while (tot < n)
        {
            ans[node[tot].pos] += R, ans[node[tot].pos + 1] += L;
            tot++;
        }
        ans[1] += L, ans[n] += R;
        for (int i = 1; i <= n; i++)
        {
            printf("%lld\n", ans[i]);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}