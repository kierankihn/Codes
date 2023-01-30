#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MOD = 1000007;
const int MAXN = 100;
const int MAXM = 100;
int n;
int m;
int a[MAXN + 5];
ll dp[MAXN + 5][MAXM + 5];
ll solve(int n_, int m_)
{
    if (m_ == 0)
    {
        return 1;
    }
    if (n_ <= 0 || m<0)
    {
        return 0;
    }
    ll &res = dp[n_][m_];
    if (res != -1)
    {
        return res;
    }
    res = 0;
    for (int i = 0; i <= a[n_]; i++)
    {
        res += solve(n_ -1, m_ - i);
        res = res % MOD;
    }
    return res;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << solve(n, m) << endl;
    return 0;
}