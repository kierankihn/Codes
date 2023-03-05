#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n, m;
int ans = 0;
int fa[MAXN + 5];
int fu[MAXN + 5];
int find(int x)
{
    if (x != fa[x])
    {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void unio(int x, int y)
{
    x = find(x);
    y = find(y);
    fa[y] = x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int p, x, y;
        cin >> p >> x >> y;
        if (p == 0)
        {
            unio(x, y);
        }
        else
        {
            if (fu[x] != 0)
            {
                unio(fu[x], y);
            }
            if (fu[y] != 0)
            {
                unio(x, fu[y]);
            }
            fu[y] = x;
            fu[x] = y;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == i)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}