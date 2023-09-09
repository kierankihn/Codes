#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 20 + 5;
    const int MAXPOS = (1 << 20) + 5;
    const int INF = 0x3f3f3f3f;
    int n;
    int mp[MAXN][MAXN];
    int dist[MAXPOS][MAXN];
    int main()
    {
        std::memset(dist, 0x3f, sizeof(dist));
        dist[1][1] = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &mp[i][j]);
            }
        }
        for (int i = 1; i <= (1 << n) - 1; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i & (1 << (j - 1)))
                {
                    int newi = i ^ (1 << (j - 1));
                    for (int k = 1; k <= n; k++)
                    {
                        if (newi & (1 << (k - 1)))
                        {
                            dist[i][j] = std::min(dist[i][j], dist[newi][k] + mp[k][j]);
                        }
                    }
                }
            }
        }
        printf("%d\n", dist[(1 << n) - 1][n]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}