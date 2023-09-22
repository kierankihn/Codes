#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e6 + 5;
    int n;
    int cnt[MAXN];
    int min[MAXN];
    int prime[MAXN];
    void getPrime()
    {
        for (int i = 2; i <= n; i++)
        {
            if (min[i] == 0)
            {
                prime[++prime[0]] = i;
            }
            for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++)
            {
                min[i * prime[j]] = prime[j];
                if (i % prime[j] == 0)
                {
                    break;
                }
            }
        }
    }
    int main()
    {
        scanf("%d", &n);
        getPrime();
        for (int i = n; i > 1; i--)
        {
            cnt[i]++;
            if (min[i] == 0)
            {
                continue;
            }
            cnt[min[i]] += cnt[i], cnt[i / min[i]] += cnt[i];
        }
        for (int i = 2; i <= n; i++)
        {
            if (min[i] == 0)
            {
                printf("%d %d\n", i, cnt[i]);
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