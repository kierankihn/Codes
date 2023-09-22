#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int INF = 0x3f3f3f3f;
    const int MAXN = 1e6 + 5;
    const int prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int n;
    int c[12] = {INF};
    LL ans = INF;
    LL cnt = 0;
    void dfs(LL now, LL num, LL cnt0)
    {
        if (now == 11)
        {
            if (cnt0 > cnt || (cnt0 == cnt && num < ans))
            {
                ans = num, cnt = cnt0;
            }
            return;
        }
        for (int i = 0; i <= c[now - 1] && num <= n; i++)
        {
            c[now] = i;
            dfs(now + 1, num, cnt0 * (i + 1));
            num = num * prime[now];
        }
    }
    int main()
    {
        scanf("%d", &n);
        dfs(1, 1, 1);
        printf("%lld\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}