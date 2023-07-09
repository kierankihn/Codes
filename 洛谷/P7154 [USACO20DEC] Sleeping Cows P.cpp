#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
const int MAXN = 3000 * 2 + 5;
int n;
pair<int, int> a[MAXN];
LL dp[2][MAXN][2];
int pre = 0, now = 1;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = 0;
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        cin >> a[i].first;
        a[i].second = 1;
    }
    sort(a + 1, a + 2 * n + 1);
    for (int i = 0; i < 2 * n; i++)
    {
        memset(dp[now], 0, sizeof(dp[now]));
        for (int j = 0; j < n; j++)
        {
            if (a[i + 1].second == 0)
            {
                dp[now][j + 1][0] += dp[pre][j][0];
                dp[now][j][1] += dp[pre][j][0];
                dp[now][j + 1][1] += dp[pre][j][1];
                dp[now][j][1] += dp[pre][j][1];
                dp[now][j][1] %= MOD, dp[now][j + 1][0] %= MOD, dp[now][j][1] %= MOD;
            }
            if (a[i + 1].second == 1)
            {
                if (j)
                {
                    dp[now][j - 1][1] += dp[pre][j][1] * j % MOD;
                    dp[now][j - 1][0] += dp[pre][j][0] * j % MOD;
                }
                dp[now][j][0] += dp[pre][j][0];
                dp[now][j - 1][0] %= MOD, dp[now][j][0] %= MOD, dp[now][j - 1][1] %= MOD;
            }
        }
        swap(now, pre);
    }
    cout << (dp[pre][0][0] + dp[pre][0][1]) % MOD << endl;
    return 0;
}