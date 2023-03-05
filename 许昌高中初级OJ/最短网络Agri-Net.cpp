#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int INF = 0x3f3f3f3f;
int n;
int ans = 0;
int vis[MAXN + 5];
int lowcost[MAXN + 5];
int cost[MAXN + 5][MAXN + 5];
int main()
{
    memset(lowcost, 0x3f, sizeof(lowcost));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
        }
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
        ans += lowcost[i];
    }
    cout << ans << endl;
    return 0;
}