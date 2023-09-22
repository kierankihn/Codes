#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e7 + 5;
    int n;
    LL ans = 0;
    LL prime[MAXN], min[MAXN], phi[MAXN], sum[MAXN];
    int main()
    {
        scanf("%d", &n);
        for (int i = 2; i <= n; i++)
        {
            if (min[i] == 0)
            {
                min[i] = i, prime[++prime[0]] = i, phi[i] = i - 1;
            }
            for (int j = 1; j <= prime[0] && i * prime[j] <= n && prime[j] <= min[i]; j++)
            {
                min[i * prime[j]] = prime[j];
                phi[i * prime[j]] = phi[i] * (i % prime[j] == 0 ? prime[j] : prime[j] - 1);
            }
        }
        for (int i = 2; i <= n; i++)
        {
            sum[i] = sum[i - 1];
            if (min[i] == i)
            {
                sum[i]++;
            }
        }
        for (int i = 2; i <= n; i++)
        {
            ans += phi[i] * sum[n / i] * 2;
        }
        ans += prime[0];
        printf("%lld\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}