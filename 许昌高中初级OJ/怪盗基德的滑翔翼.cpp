#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int n;
int ans1 = 1,ans2=1;
int ansk;
int nums[MAXN + 5];
int nums_t[MAXN + 5];
int dp[MAXN + 5][2];
int vis[MAXN + 5];
int solve(int k)
{
    if (vis[k])
    {
        return dp[k][0];
    }
    else
    {
        for (int i = 1; i < k; i++)
        {
            if (nums[k] < nums[i])
            {
                if (dp[k][0] < solve(i) + 1)
                {
                    dp[k][0] = solve(i) + 1;
                    dp[k][1] = i;
                }
            }
        }
    }
    vis[k] = 1;
    return dp[k][0];
}
int main()
{
    int K;
    cin>>K;
    while(K--)
    {
        memset(vis, 0, sizeof(vis));
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
            nums_t[i] = nums[i];
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            if (ans1 < solve(i))
            {
                ans1 = solve(i);
                ansk = i;
            }
        }
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++)
        {
            nums[i] = nums_t[n - i + 1];
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            if (ans2 < solve(i))
            {
                ans2 = solve(i);
                ansk = i;
            }
        }
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}
