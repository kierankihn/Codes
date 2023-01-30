#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n,m;
int mp[MAXN + 5][MAXN + 5];
int dp[MAXN + 5][MAXN + 5];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> mp[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + mp[i][j];
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}