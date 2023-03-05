#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
int n, m;
int fa[2 * MAXN * MAXN + 5];
int count(pair<int, int> x)
{
    return x.first + (x.second - 1) * n;
}
int find(int x)
{
    if (fa[x] != x)
    {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
bool merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return true;
    }
    fa[y] = x;
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n * n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        char pos;
        pair<int, int> u, v;
        cin >> u.first >> u.second;
        cin >> pos;
        if (pos == 'D')
        {
            v.first = u.first;
            v.second = u.second - 1;
        }
        else
        {
            v.first = u.first + 1;
            v.second = u.second;
        }
        if (merge(count(u), count(v)))
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << "draw" << endl;
    return 0;
}