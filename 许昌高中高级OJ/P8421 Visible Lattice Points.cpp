#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int N = 1e6;
    const int MAXN = 1e6 + 5;
    int c;
    int n;
    int prime[MAXN], min[MAXN], phi[MAXN];
    LL ans[MAXN];
    int main()
    {
        scanf("%d", &c);
        for (int i = 2; i <= N; i++)
        {
            if (min[i] == 0)
            {
                min[i] = i, prime[++prime[0]] = i, phi[i] = i - 1;
            }
            for (int j = 1; j <= prime[0] && i * prime[j] <= N && prime[j] <= min[i]; j++)
            {
                min[i * prime[j]] = prime[j];
                phi[i * prime[j]] = phi[i] * (i % prime[j] == 0 ? prime[j] : prime[j] - 1);
            }
        }
        for (int i = 1; i <= N; i++)
        {
            ans[i] = ans[i - 1] + phi[i];
        }
        for (int i = 1; i <= c; i++)
        {
            scanf("%d", &n);
            printf("%d %d %lld\n", i, n, ans[n] * 2 + 3);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}