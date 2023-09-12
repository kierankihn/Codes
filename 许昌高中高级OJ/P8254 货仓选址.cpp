#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    int n;
    int pos;
    int ans = 0;
    int a[MAXN];
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        std::sort(a + 1, a + n + 1);
        if (n % 2 == 0)
        {
            pos = (a[n / 2] + a[n / 2 + 1]) / 2;
        }
        else
        {
            pos = a[n / 2 + 1];
        }
        for (int i = 1; i <= n; i++)
        {
            ans += std::abs(a[i] - pos);
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