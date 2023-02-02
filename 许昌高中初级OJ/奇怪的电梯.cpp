#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
int n;
int a, b;
int k[MAXN + 5];
int vis[MAXN + 5];
int main()
{
    queue<int> d;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    memset(vis, -1, sizeof(vis));
    d.push(a);
    vis[a] = 0;
    while (!d.empty())
    {
        int tmp1, tmp2;
        tmp1 = d.front() + k[d.front()];
        tmp2 = d.front() - k[d.front()];
        if (tmp1 >= 1 && tmp1 <= n && (vis[tmp1] == -1))
        {
            vis[tmp1] = vis[d.front()] + 1;
            d.push(tmp1);
        }
        if (tmp2 >= 1 && tmp2 <= n && (vis[tmp2] == -1))
        {
            vis[tmp2] = vis[d.front()] + 1;
            d.push(tmp2);
        }
        if (tmp1 == b || tmp2 == b)
        {
            break;
        }
        d.pop();
    }
    cout << vis[b] << endl;
    return 0;
}