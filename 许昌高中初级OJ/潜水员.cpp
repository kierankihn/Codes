#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000;
const int MAXVN = 79;
const int MAXVO = 21;
int vn, vo;
int n;
int cn[MAXN + 5], co[MAXN + 5], w[MAXN + 5];
int dp[MAXVN + 5][MAXVO + 5][MAXN + 5];
int solve(int vn_, int vo_, int k)
{
    if (vn_ <= 0 && vo_ <= 0)
    {
        return 0;
    }
    if (vn_ <= 0)
    {
        vn_ = 0;
    }
    if (vo_ <= 0)
    {
        vo_ = 0;
    }
    if (k < 1)
    {
        return dp[vn_][vo_][k] = INF + 1;
    }
    if (dp[vn_][vo_][k] != INF)
    {
        return dp[vn_][vo_][k];
    }
    int res = INF;
    res = min(solve(vn_ - cn[k], vo_ - co[k], k - 1) + w[k], solve(vn_, vo_, k - 1));
    return dp[vn_][vo_][k] = res;
}
int main()
{
    vector<int> vis;
    cin >> vo >> vn;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> co[i] >> cn[i] >> w[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    cout << solve(vn, vo, n) << endl;
    return 0;
}