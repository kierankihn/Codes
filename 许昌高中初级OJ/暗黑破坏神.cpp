#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int MAXM = 500;
const int MAXLEVEL = 50;
long long level[MAXN + 5];           // 魔法的等级数量
long long price[MAXN + 5];           // 魔法书价格
long long w[MAXN + 5][MAXLEVEL + 5]; // 魔法效果值
long long n;                         // 魔法数量
long long m;                         // 金币数量
long long dp[MAXN + 5][MAXM + 5];
long long ans[MAXN + 5][MAXM + 5];
long long output[MAXN + 5];
long long solve(long long n_, long long m_)
{
    if (n_ < 1 || m_ <= 0)
    {
        return 0;
    }
    long long &res = dp[n_][m_];
    if (res != -1)
    {
        return res;
    }
    for (int i = 0; i <= level[i]; i++)
    {
        if (m_ - price[n_] * i >= 0)
        {
            if (res < solve(n_ - 1, m_ - price[n_] * i) + w[n_][i])
            {
                res = solve(n_ - 1, m_ - price[n_] * i) + w[n_][i];
                ans[n_][m_] = i;
            }
        }
    }
    return res;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    memset(w, 0, sizeof(w));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i] >> level[i];
        for (int j = 1; j <= n; j++)
        {
            cin >> w[i][j];
        }
    }
    cout << solve(n, m) << endl;
    int tmp = m;
    for (int i = n; i >= 1; i--)
    {
        output[i] = ans[i][tmp];
        tmp = tmp - ans[i][tmp] * price[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cout<< output[i] << endl;
    }
    return 0;
}