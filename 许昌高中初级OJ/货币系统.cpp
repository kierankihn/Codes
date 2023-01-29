#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long MAXN = 20;
const long long MAXS = 3000;
long long nums[MAXN + 5];
long long dp[MAXN + 5][MAXS + 5];
long long n, sum;
long long solve(long long n_, long long sum_)
{
    long long res = 0;
    if (sum_ == 0)
    {
        return 1;
    }
    if (n_ <= 0)
    {
        return 0;
    }
    if (dp[n_][sum_] != -1)
    {
        return dp[n_][sum_];
    }
    else
    {
        for (long long j = 0; j * nums[n_] <= sum_; j++)
        {
            res += solve(n_ - 1, sum_ - j * nums[n_]);
        }
    }
    return dp[n_][sum_] = res;
}
int main()
{
    cin >> n >> sum;
    for (long long i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    sort(nums + 1, nums + n + 1);
    // n = unique(nums + 1, nums + n + 1) - nums - 1;
    memset(dp, -1, sizeof(dp));
    cout << solve(n, sum) << endl;
    return 0;
}