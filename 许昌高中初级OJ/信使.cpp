#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int INF = 0x3f3f3f3f;
int n, m;
int ans = -1;
int mp[MAXN + 5][MAXN + 5];
int main()
{
    memset(mp, 0x3f, sizeof(mp));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        mp[u][v] = mp[v][u] = d;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, mp[1][i]);
    }
    cout << ((ans == INF) ? -1 : ans) << endl;
    return 0;
}