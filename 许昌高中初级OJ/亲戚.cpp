#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20000;
int n, m, q;
int fa[MAXN + 5];
int find(int x)
{
    if (fa[x] != x)
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
    memset(fa, -1, sizeof(fa));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        unio(u, v);
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        if(find(x)==find(y))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}