#include <bits/stdc++.h>
using namespace std;
const int MAXV = 200;
const int MAXN = 30;
const int MAXT = 10;
int v;             // 背包容量
int n;             // 物品件数
int t;             // 分组数量
int w[MAXT][MAXN]; // 物品重量
int c[MAXT][MAXN]; // 物品价值
int dp[MAXT][MAXV];
int main()
{
    cin >> v >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        int wi, ci, pi;
        cin >> wi >> ci >> pi;
        w[pi][0]++;
        c[pi][0]++;
        w[pi][w[pi][0]] = wi;
        c[pi][c[pi][0]] = ci;
    }
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = 1; j <= w[i][0]; j++)
        {
            for (int k = w[i][j]; k <= v; k++)
            {
                dp[i][k] = max(dp[i][k], dp[i - 1][k - w[i][j]] + c[i][j]);
            }
        }
    }
    cout << dp[t][v] << endl;
    return 0;
}