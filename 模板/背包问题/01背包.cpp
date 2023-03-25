#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int v;
    int c[35], w[35];
    int dp[35][205];
    cin >> v >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= 1; j--)
        {
            if (j - w[i] >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][v] << endl;
    return 0;
}