#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int m;
ll ans = 0x3f3f3f3f;
int nums[20005];
ll sum[20005];
int main()
{
    sum[0] = 0;
    ans = ans * ans * (-1);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        sum[i] = sum[i - 1] + nums[i];
    }
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n && j < i + m; j++)
        {
            ans = max(ans, sum[j] - sum[i - 1]);
        }
    }
    cout << ans << endl;
    return 0;
}