#include <bits/stdc++.h>
using namespace std;
const int MAXL = 100;
const int MAXN = 6;
int n;
string num;
int dp[MAXL + 5][MAXN + 5];
int solve(int l, int k)
{
    if (dp[l][k] != -1)
    {
        return dp[l][k];
    }
    int res = -1;
    if (k == 0)
    {
        return dp[l][k] = stoi(num.substr(0, l));
    }
    for (int i = 1; i < l; i++)
    {
        res = max(res, solve(i, k - 1) * stoi(num.substr(i, l - i)));
    }
    return dp[l][k] = res;
}
int main()
{
    cin >> n >> n;
    cin >> num;
    memset(dp, -1, sizeof(dp));
    cout << solve(num.size(), n) << endl;
    return 0;
}