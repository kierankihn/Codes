#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3;
int n;
int P1[MAXN + 5];
int P2[MAXN + 5];
int dp[MAXN + 5][MAXN + 5];
int solve(int x, int y)
{
    int ans = 0;
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
        ans = max(solve(x, y - 1), ans);
        ans = max(solve(x - 1, y), ans);
        if (P1[x] == P2[y])
        {
            ans = max(solve(x - 1, y - 1) + 1, ans);
        }
    }
    return dp[x][y] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> P1[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> P2[i];
    }
    if (P1[1] == P2[1])
    {
        dp[1][1] = 1;
    }
    else
    {
        dp[1][1] = 0;
    }
    cout << solve(n, n) << endl;
    return 0;
}