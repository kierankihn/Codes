#include <bits/stdc++.h>
using namespace std;
const int MAXM = 15;
const int MAXN = 10;
int n, m;
int gain[MAXN + 5][MAXM + 5];
int dp[MAXN + 5][MAXN + 5];
int ans[MAXN + 5];
int solve(int x, int y)
{
    int res = -1;
    if (x < 1 || y < 1)
    {
        return 0;
    }
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    else
    {
        for (int i = 0; i <= y; i++)
        {
            if (res < solve(x - 1, y - i) + gain[x][i])
            {
                res = solve(x - 1, y - i) + gain[x][i];
                ans[x] = i;
            }
        }
    }
    return dp[x][y] = res;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        gain[i][0] = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> gain[i][j];
        }
    }
    cout << solve(n, m) << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << ans[i] << endl;
    }
    return 0;
}