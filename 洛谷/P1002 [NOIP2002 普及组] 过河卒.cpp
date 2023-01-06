#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int bx, by, mx, my;
long long dp[MAXN + 5][MAXN + 5];
int dx[9] = {0, 1, 1, 2, 2, -1, -1, -2, -2};
int dy[9] = {0, 2, -2, 1, -1, 2, -2, 1, -1};
long long solve(int x, int y)
{
    long long ans = 0;
    if (x < 0 || x > bx || y < 0 || y > by)
    {
        return 0;
    }
    if (dp[x][y] != -1)
    {
        ans = dp[x][y];
    }
    else
    {
        ans = solve(x - 1, y) + solve(x, y - 1);
    }
    return dp[x][y] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> bx >> by >> mx >> my;
    dp[0][0] = 1;
    for (int i = 0; i < 9; i++)
    {
        if ((mx + dx[i] >= 0 && mx + dx[i] <= bx) && (my + dy[i] >= 0 && my + dy[i] <= by))
        {
            dp[mx + dx[i]][my + dy[i]] = 0;
        }
    }
    cout << solve(bx, by) << endl;

    return 0;
}
