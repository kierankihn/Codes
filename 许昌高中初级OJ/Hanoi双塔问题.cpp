#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
int vis[MAXN + 5];
unsigned __int128 dp[MAXN + 5];
unsigned __int128 h(int s)
{
    if (vis[s])
    {
        return dp[s];
    }
    vis[s] = 1;
    return dp[s] = 2 * h(s - 1) + 2;
}
void print(unsigned __int128 a)
{
    if (!a)
    {
        return;
    }
    print(a / 10);
    putchar(a % 10 + '0');
}
int main()
{
    // vis[0] = 1;
    // int n;
    // cin >> n;
    // // cout << h(n) << endl;
    // print(h(n));
    // cout << endl;
    // return 0;
    int n;
    int ans[210];
    int j;
    cin >> n;
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++)
    {
        for (j = 1; j <= 200; j++)
            ans[j] = ans[j] * 2;
        ans[1]++;
        for (j = 1; j <= 200; j++)
            if (ans[j] >= 10)
            {
                ans[j + 1] += ans[j] / 10;
                ans[j] = ans[j] % 10;
            }
    }
    for (j = 1; j <= 200; j++)
        ans[j] = ans[j] * 2;
    for (j = 1; j <= 200; j++)
        if (ans[j] >= 10)
        {
            ans[j + 1] += ans[j] / 10;
            ans[j] = ans[j] % 10;
        }
    bool p = 0;
    for (int i = 200; i >= 1; i--)
    {
        if (ans[i] != 0)
            p = 1;
        if (p)
            printf("%d", ans[i]);
    }
    cout << endl;
}