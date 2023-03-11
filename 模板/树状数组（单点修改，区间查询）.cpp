#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int n, m;
int a[MAXN + 5];
int s[MAXN + 5];
int lowbit(int _x)
{
    return (_x) & (-_x);
}
int query(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += s[x];
        x -= lowbit(x);
    }
    return res;
}
void add(int x, int y)
{
    while (x <= n)
    {
        s[x] += y;
        x += lowbit(x);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        add(i, x);
    }
    for (int i = 1; i <= m; i++)
    {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 0)
        {
            cout << query(b) - query(a - 1) << endl;
        }
        else
        {
            add(a, b);
        }
    }
    return 0;
}