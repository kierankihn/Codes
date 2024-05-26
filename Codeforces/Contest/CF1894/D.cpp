#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e5 + 5;
    int t;
    int n, m;
    int p, q;
    int tot = 0;
    int a[MAXN], b[MAXN], c[MAXN * 2];
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            scanf("%d%d", &n, &m);
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &a[i]);
            }
            for (int i = 1; i <= m; i++)
            {
                scanf("%d", &b[i]);
            }
            std::sort(b + 1, b + m + 1, std::greater<int>());
            for (p = 1, q = 0; p <= n && q <= m; p++)
            {
                while (q + 1 <= m && b[q + 1] >= a[p])
                {
                    c[p + q] = b[q + 1], q++;
                }
                c[p + q] = a[p];
            }
            while (q <= m)
            {
                c[p + q] = b[q + 1], q++;
            }
            for (int i = 1; i <= n + m; i++)
            {
                printf("%d%c", c[i], i == n + m ? '\n' : ' ');
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