#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1000 + 5;
    int ans = 0;
    int n, k;
    int a[MAXN];
    int main()
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        std::sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            ans = std::max(ans, (int)(std::upper_bound(a + 1, a + n + 1, a[i] + k) - a - i));
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