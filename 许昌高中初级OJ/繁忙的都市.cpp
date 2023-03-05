#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int INF = 0x3f3f3f3f;
int n;
int m;
int ans = -1;
int sum = 0;
int vis[MAXN + 5];
int lowcost[MAXN + 5];
int cost[MAXN + 5][MAXN + 5];
int main()
{
    memset(cost, 0x3f, sizeof(cost));
    memset(lowcost, 0x3f, sizeof(lowcost));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        cin >> cost[u][v];
        cost[v][u] = cost[u][v];
        sum += cost[u][v];
    }
    lowcost[1] = 0;
    for (int j = 1; j <= n; j++)
    {
        int minv = INF, minp = 0;
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
    cout << n - 1 << endl;
    cout << ans << endl;
    return 0;
}