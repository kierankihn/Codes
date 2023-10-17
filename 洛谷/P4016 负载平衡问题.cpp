#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e3 + 5;
    const int INF = 0x3f3f3f3f;
    int n;
    int ans = 0;
    int avr = 0;
    int a[MAXN];
    int sum[MAXN];
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            avr += a[i], sum[i] = sum[i - 1] + a[i];
        }
        avr = avr / n;
        for (int i = 1; i <= n; i++)
        {
            sum[i] -= i * avr;
        }
        std::sort(sum + 1, sum + n + 1);
        for (int i = 1; i <= n; i++)
        {
            ans += std::abs(sum[n / 2 + 1] - sum[i]);
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