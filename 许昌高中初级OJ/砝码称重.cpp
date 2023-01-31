#include <bits/stdc++.h>
using namespace std;
const int n = 6;
const int MAXN = 1000;
const int w[n + 1] = {0, 1, 2, 3, 5, 10, 20};
int sum = 0;
int ans = 0;
int nums[n + 1];
int dp[MAXN + 5];
int main()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        sum += nums[i] * w[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= nums[i]; j++)
        {
            for (int k = sum; k >= w[i] * j; k--)
            {
                dp[k] = max(dp[k], dp[k - w[i] * j]);
            }
        }
    }
    for (int i = 1; i <= sum; i++)
    {
        if (dp[i])
        {
            ans++;
        }
    }
    cout << "Total=" << ans << endl;
    return 0;
}