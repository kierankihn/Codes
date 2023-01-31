#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 20000;
const int MAXM = 20000;
int n;
int m;
int l = 0;
ll ans = -1;
int nums[MAXN + 5];
ll dp[MAXN + 5];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        if (l < m)
        {
            l++;
            if (dp[i - 1] + nums[i] <= nums[i])
            {
                l = 1;
                dp[i] = nums[i];
            }
            else
            {
                dp[i] = dp[i - 1] + nums[i];
            }
        }
        else
        {
            if (dp[i - 1] + nums[i] - nums[i - l] <= nums[i])
            {
                l = 1;
                dp[i] = nums[i];
            }
            else
            {
                dp[i] = dp[i - 1] + nums[i] - nums[i - l];
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}