#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int n;
int c;
int k = 0;
int v[MAXN * MAXN + 5];
int w[MAXN * MAXN + 5];
int dp[MAXN*MAXN + 5];
int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        int vi, si, wi;
        cin >> vi >> wi >> si;
        for (int j = 1; j <= si; j++)
        {
            k++;
            v[k] = vi;
            w[k] = wi;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = c; j >= 1; j--)
        {
            if (j - v[i] >= 0)
            {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }
    cout << dp[c] << endl;
    return 0;
}