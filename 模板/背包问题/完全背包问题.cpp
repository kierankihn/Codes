#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int v;
    int c[35], w[35];
    int dp[205];
    cin >> v >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (j - w[i] >= 0)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
            }
        }
    }
    cout << "max=" << dp[v] << endl;
    return 0;
}