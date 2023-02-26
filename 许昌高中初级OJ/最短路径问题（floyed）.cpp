#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int n, m;
int s, t;
int pos[MAXN + 5][3];
double dis[MAXN + 5][MAXN + 5];
int main()
{
    memset(dis, 127, sizeof(dis));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pos[i][1] >> pos[i][2];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        dis[y][x] = dis[x][y] = sqrt((pos[x][1] - pos[y][1]) * (pos[x][1] - pos[y][1]) + (pos[x][2] - pos[y][2]) * (pos[x][2] - pos[y][2]));
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[j][i] = dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
            }
        }
    }
    cin >> s >> t;
    cout << fixed << setprecision(2) << dis[s][t] << endl;
    return 0;
}