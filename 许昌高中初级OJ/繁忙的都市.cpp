#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 300;
const int INF = 0x3f3f3f3f;
LL n;
LL m;
LL ans = -1;
LL sum = 0;
LL vis[MAXN + 5];
LL lowcost[MAXN + 5];
LL cost[MAXN + 5][MAXN + 5];
int main()
{
    memset(cost, 0x3f, sizeof(cost));
    memset(lowcost, 0x3f, sizeof(lowcost));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        LL u, v;
        cin >> u >> v;
        cin >> cost[u][v];
        cost[v][u] = cost[u][v];
        sum += cost[u][v];
    }
    lowcost[1] = 0;
    for (int j = 1; j <= n; j++)
    {
        LL minv = INF, minp = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            if (lowcost[i] < minv)
            {
                minv = lowcost[i];
                minp = i;
            }
        }
        vis[minp] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            lowcost[i] = min(lowcost[i], cost[minp][i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, lowcost[i]);
    }
    cout << n - 1 << " ";
    cout << ans << endl;
    return 0;
}