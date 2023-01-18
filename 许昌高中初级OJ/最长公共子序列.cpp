#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
string p1, p2;
int dp[MAXN + 5][MAXN + 5];
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
        res = max(res, solve(x, y - 1));
        res = max(res, solve(x - 1, y));
        if (p1[x - 1] == p2[y - 1])
        {
            res = max(res, solve(x - 1, y - 1) + 1);
        }
    }
    return dp[x][y] = res;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> p1 >> p2;
    cout << solve(p1.size(), p2.size()) << endl;
    return 0;
}