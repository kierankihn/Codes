#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 18 + 5;
    const int MAXSZ = (1 << 18) + 5;
    const int INF = 0x3f3f3f3f;
    int n, w;
    int ans = INF;
    LL a[MAXN];
    LL c[MAXN];
    void solve(int now, int cnt)
    {
        if (cnt > ans)
        {
            return;
        }
        if (now == n + 1)
        {
            ans = std::min(ans, cnt);
            return;
        }
        for (int i = 1; i <= cnt; i++)
        {
            if (a[now] + c[i] <= w)
            {
                c[i] += a[now];
                solve(now + 1, cnt);
                c[i] -= a[now];
            }
        }
        c[++cnt] = a[now];
        solve(now + 1, cnt);
        c[cnt--] = 0;
    }
    int main()
    {
        scanf("%d%d", &n, &w);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
        }
        std::sort(a + 1, a + n + 1);
        std::reverse(a + 1, a + n + 1);
        solve(0, 0);
        printf("%d\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}