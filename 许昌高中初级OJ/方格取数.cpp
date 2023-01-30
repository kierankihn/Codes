#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10;
int n;
int mp[MAXN + 5][MAXN + 5];
int dp[MAXN + 5][MAXN + 5][2 * MAXN + 5];
int solve(int x, int y, int k)
{
    if(x<=0 || y<=0 || k<0)
    {
        return 0;
    }
    int ax, ay, bx, by;
    ax = x;
    ay = k + 2 - x;
    bx = y;
    by = k + 2 - y;
    if (dp[x][y][k] != -1)
    {
        return dp[x][y][k];
    }
    dp[x][y][k] = max(max(solve(x, y, k - 1), solve(x, y - 1, k - 1)), max(solve(x - 1, y, k - 1), solve(x - 1, y - 1, k - 1)));
    dp[x][y][k] += mp[ax][ay] + mp[bx][by];
    if (ax == bx && ay == by)
    {
        dp[x][y][k] -= mp[ax][ay];
    }
    return dp[x][y][k];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    memset(mp, 0, sizeof(mp));
    cin >> n;
    int x_, y_, n_;
    while (cin >> x_ >> y_ >> n_ && x_ && y_ && n_)
    {
        mp[x_][y_] = n_;
    }
    dp[1][1][0] = mp[1][1];
    cout << solve(n, n, 2 * n - 2) << endl;
    return 0;
}