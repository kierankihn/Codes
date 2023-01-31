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
    vis[0] = 1;
    int n;
    cin >> n;
    // cout << h(n) << endl;
    print(h(n));
    cout << endl;
    return 0;
}