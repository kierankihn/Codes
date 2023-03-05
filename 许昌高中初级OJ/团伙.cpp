#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n, m;
int ans = 0;
int fa[MAXN + 5];
set<int> fu[MAXN + 5];
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
        if (p == 1)
        {
            unio(x, y);
            for (set<int>::iterator j = fu[x].begin(); j != fu[x].end(); j++)
            {
                fu[y].insert(*j);
                fu[*j].insert(x);
            }
            for (set<int>::iterator j = fu[y].begin(); j != fu[y].end(); j++)
            {
                fu[x].insert(*j);
                fu[*j].insert(y);
            }
        }
        else
        {
            fu[x].insert(y);
            fu[y].insert(x);
            for (set<int>::iterator j = fu[x].begin(); j != fu[x].end(); j++)
            {
                if (!fu[x].count(*j))
                {
                    unio(x, *j);
                }
            }
            for (set<int>::iterator j = fu[y].begin(); j != fu[y].end(); j++)
            {
                if (!fu[y].count(*j))
                {
                    unio(*j, y);
                }
            }
        }
    }
    set<int> tmp;
    for (int i = 1; i <= n; i++)
    {
        if (!tmp.count(find(i)))
        {
            ans++;
            tmp.insert(find(i));
        }
    }
    cout << ans << endl;
    return 0;
}