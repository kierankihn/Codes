#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e5 + 5;
    int n;
    int cnt[25];
    int a[MAXN], b[MAXN], c[MAXN];
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i < n; i++)
        {
            scanf("%d", &a[i]);
            c[i] = c[i - 1] ^ a[i];
            for (int j = 1; j <= 20; j++)
            {
                if (c[i] & (1 << (j - 1)))
                {
                    cnt[j]++;
                }
            }
        }
        for (int i = 1; i <= 20; i++)
        {
            if (cnt[i] > n - 1 - cnt[i])
            {
                b[1] = b[1] | (1 << (i - 1));
            }
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d%c", b[1] ^ c[i - 1], i == n ? '\n' : ' ');
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}