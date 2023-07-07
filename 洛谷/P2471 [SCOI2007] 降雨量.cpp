#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 5e4 + 5;
int n, m;
int year[MAXN], val[MAXN];
int st[MAXN][20];
map<int, int> mp;
void build()
{
    for (int i = 1; i <= n; i++)
    {
        st[i][0] = val[i];
    }
    for (int j = 1; 1 << j <= n; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int query(int l, int r)
{
    int len = r - l + 1;
    int k = 0;
    while ((1 << (k + 1)) < len)
    {
        k++;
    }
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}
void output(string str)
{
    cout << str << endl;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> year[i] >> val[i];
        mp[year[i]] = i;
    }
    build();
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        int u, v;
        bool k1, k2;
        cin >> x >> y;
        u = lower_bound(year + 1, year + n + 1, x) - year;
        v = lower_bound(year + 1, year + n + 1, y) - year;
        k1 = (u != n + 1 && x == year[u]);
        k2 = (v != n + 1 && y == year[v]);
        if (!k1 && !k2)
        {
            output("maybe");
            continue;
        }
        if (k1 && k2)
        {
            if (val[v] >= val[u])
            {
                output("false");
                continue;
            }
            if (year[u] + 1 == year[v])
            {
                output("true");
                continue;
            }
            if (u + 1 == v)
            {
                output("maybe");
                continue;
            }
            int maxr = query(u + 1, v - 1);
            if (maxr >= val[v])
            {
                output("false");
                continue;
            }
            if (v - u == year[v] - year[u])
            {
                output("true");
                continue;
            }
            if (v - u < year[v] - year[u])
            {
                output("maybe");
                continue;
            }
        }
        if (k1)
        {
            if (u + 1 == v)
            {
                output("maybe");
                continue;
            }
            int maxr = query(u + 1, v - 1);
            if (maxr >= val[u])
            {
                output("false");
                continue;
            }
            if (maxr < val[u])
            {
                output("maybe");
                continue;
            }
        }
        if (k2)
        {
            if (u == v)
            {
                output("maybe");
                continue;
            }
            int maxr = query(u, v - 1);
            if (maxr < val[v])
            {
                output("maybe");
                continue;
            }
            if (maxr >= val[v])
            {
                output("false");
                continue;
            }
        }
    }
    return 0;
}