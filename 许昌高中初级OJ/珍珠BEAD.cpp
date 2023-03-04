#include <bits/stdc++.h>
using namespace std;
const int MAXN = 99;
int n, m;
int cnt = 0;
int mp[MAXN + 5][MAXN + 5];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        mp[u][v] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                mp[i][j] = mp[i][j] || (mp[i][k] && mp[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mp[i][j])
            {
                mp[i][0]++;
                mp[0][j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp[i][0] >= ((n + 1) / 2))
        {
            cnt++;
        }
        if (mp[0][i] >= ((n + 1) / 2))
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}
