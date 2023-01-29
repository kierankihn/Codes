#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXL = 2000;
string a, b;
int dp[MAXL + 5][MAXL + 5];
int solve(int x, int y)
{
    if (x <= 0 || y <= 0)
    {
        return max(0, max(x, y));
    }
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    int res = INF;
    if (a[x-1] == b[y-1])
    {
        res = min(res, solve(x - 1, y - 1));
    }
    res = min(res, solve(x - 1, y) + 1);
    res = min(res, solve(x, y - 1) + 1);
    res = min(res, solve(x - 1, y - 1) + 1);
    return dp[x][y] = res;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    cout << solve(a.size(), b.size()) << endl;
    // cout << a.size() << " " << b.size() << endl;
    return 0;
}