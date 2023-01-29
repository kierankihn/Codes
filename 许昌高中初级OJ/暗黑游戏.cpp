#include <bits/stdc++.h>
using namespace std;
const int MAXN = 150;
const int MAXP = 100;
const int MAXR = 100;
int n;
int vp, vr;
int wp[MAXN + 5];
int wr[MAXN + 5];
int c[MAXN + 5];
int s[MAXN + 5];
int dp[MAXP + 5][MAXR + 5];
int main()
{
    cin >> n >> vp >> vr;
    for (int i = 1; i <= n; i++)
    {
        cin >> wp[i] >> wr[i]>> s[i]>>c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 0)
        {
            for (int j = wp[i]; j <= vp; j++)
            {
                for (int k = wr[i]; k <= vr;k++)
                {
                    dp[j][k] = max(dp[j][k], dp[j - wp[i]][k - wr[i]] + c[i]);
                }
            }
        }
        if (s[i] != 0)
        {
            for (int hz = 1; hz <= s[i];hz++)
            {
                for (int j = vp; j >= wp[i]; j--)
                {
                    for (int k = vr; k >= wr[i]; k--)
                    {
                        dp[j][k] = max(dp[j][k], dp[j - wp[i]][k - wr[i]] + c[i]);
                    }
                }
            }
        }
    }
    cout << dp[vp][vr];
    return 0;
}