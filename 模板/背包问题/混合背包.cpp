#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30;
const int MAXV = 200;
const int MAXS = 100;
int v, n;
int k = 0;
int w[MAXN * MAXS + 5];
int c[MAXN * MAXS + 5];
int p[MAXN * MAXS + 5];
int dp[MAXV + 5];
int main()
{
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
    {
        int wi, ci, pi;
        cin >> wi >> ci >> pi;
        if (pi != 0)
        {
            for (int j = 1; j <= pi; j++)
            {
                k++;
                w[k] = wi;
                c[k] = ci;
                p[k] = 1;
            }
        }
        else
        {
            k++;
            w[k] = wi;
            c[k] = ci;
            p[k] = 0;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        if (p[i] == 0)
        {
            for (int j = w[i]; j <= v; j++)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
            }
        }
        else
        {
            for (int j = v; j >= w[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
            }
        }
    }
    cout << dp[v] << endl;
    return 0;
}