#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
const int MAXK = 50;
int n, k, p, t, pre, ans;
int num[MAXK + 5];
int cost[MAXN + 5];
int color[MAXN + 5];
int main()
{
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> color[i] >> cost[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (cost[i] <= p)
        {
            t = i;
            for (int j = pre + 1; j <= t; j++)
            {
                num[color[j]]++;
            }
            pre = t;
            ans--;
        }
        ans += num[color[i]];
    }
    cout << ans << endl;
    return 0;
}