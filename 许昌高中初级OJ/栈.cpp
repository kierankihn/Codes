#include <bits/stdc++.h>
using namespace std;
const int MAXN = 18;
int dp[MAXN + 5];
int solve(int n_)
{
    if(dp[n_]!=-1)
    {
        return dp[n_];
    }
    dp[n_] = 0;
    for (int i = 0; i <= n_ - 1; i++)
    {
        dp[n_] += solve(i) * solve(n_ - i - 1);
    }
    return dp[n_];
}
int n;
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    dp[0] = dp[1] = 1;
    cout << solve(n) << endl;
    return 0;
}