#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30;
const int MAXV = 20000;
int v;
int n;
int w[MAXN + 5];
int c[MAXN + 5];
int dp[MAXV + 5];
int main()
{
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        c[i] = w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
        }
    }
    cout << v-dp[v] << endl;
    return 0;
}