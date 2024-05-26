#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1000 + 5;
    const int INF = 0x3f3f3f3f;
    int t;
    int n;
    LL ans = 0;
    int a[MAXN];
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            ans = 0;
            scanf("%d", &n);
            for (int i = 1; i <= 2 * n; i++)
            {
                scanf("%d", &a[i]);
            }
            std::sort(a + 1, a + 2 * n + 1);
            for (int i = 1; i < n; i++)
            {
                ans += a[i + 1] - a[i];
                ans += a[i + n + 1] - a[i + n];
            }
            printf("%lld\n", ans);
            for (int i = 1; i <= n; i++)
            {
                printf("%d %d\n", a[i], a[i + n]);
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}