#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000;
int n, m, q;
long long c[MAXN + 5][MAXN + 5];
inline int lowbit(int x)
{
    return x & (-x);
}
void update(int x_, int y_, int a)
{
    for (int i = x_; i <= n; i += lowbit(i))
    {
        for (int j = y_; j <= n; j += lowbit(j))
        {
            c[i][j] += a;
        }
    }
}
long long query(int x_, int y_)
{
    long long res = 0;
    for (int i = x_; i > 0; i -= lowbit(i))
    {
        for (int j = y_; j > 0; j -= lowbit(j))
        {
            res += c[i][j];
        }
    }
    return res;
}
long long query(pair<int, int> a, pair<int, int> b)
{
    return query(b.first, b.second) - query(a.first - 1, b.second) - query(b.first, a.second - 1) + query(a.first - 1, a.second - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while (cin >> q)
    {
        if (q == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            // scanf("%d%d%d", &x, &y, &k);
            update(x, y, k);
        }
        else
        {
            pair<int, int> a, b;
            cin >> a.first >> a.second >> b.first >> b.second;
            // scanf("%d%d%d%d", &a.first, &a.second, &b.first, &b.second);
            cout << query(a, b) << endl;
            // printf("%lld\n", query(a, b));
        }
    }
    return 0;
}