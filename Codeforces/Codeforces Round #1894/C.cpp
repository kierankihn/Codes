#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e5 + 5;
    int t;
    int n, k;
    int delta;
    int b[MAXN];
    int vis[MAXN];
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            delta = 0, vis[0] = 0;
            scanf("%d%d", &n, &k);
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &b[i]);
                vis[i] = false;
            }
            for (int i = 1; i <= k; i++)
            {
                int nxt = (n + delta > n) ? delta : n;
                if (vis[nxt])
                {
                    vis[0] = true;
                    break;
                }
                if (b[nxt] > n)
                {
                    break;
                }
                vis[nxt] = true, delta = (delta + n - b[nxt]) % n;
                if (i == k)
                {
                    vis[0] = true;
                }
            }
            if (vis[0])
            {
                puts("Yes");
            }
            else
            {
                puts("No");
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