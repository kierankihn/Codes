#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
int n, m;
int vis[MAXN * 4 + 5];
long long a[MAXN * 4 + 5];
long long sum[MAXN * 4 + 5];
inline int readInt()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void write(long long x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
    return;
}
void build(int o, int l, int r)
{
    if (l == r)
    {
        sum[o] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(o * 2, l, mid);
    build(o * 2 + 1, mid + 1, r);
    sum[o] = sum[o * 2] + sum[o * 2 + 1];
}
void update(int o, int ql, int qr, int l, int r)
{
    if (r < ql || qr < l)
    {
        return;
    }
    if (vis[o])
    {
        return;
    }
    int mid = (l + r) / 2;
    if (l == r)
    {
        sum[o] = sqrt(sum[o]);
        if (sum[o] == 1)
        {
            vis[o] = 1;
        }
        return;
    }
    else
    {
        if (mid >= ql)
        {
            update(o * 2, ql, qr, l, mid);
        }
        if (mid <= qr)
        {
            update(o * 2 + 1, ql, qr, mid + 1, r);
        }
        sum[o] = sum[o * 2] + sum[o * 2 + 1];
        if (vis[2 * o] && vis[2 * o + 1])
        {
            vis[o] = 1;
        }
    }
}
void update(int l, int r)
{
    update(1, l, r, 1, n);
}
long long query(int o, int ql, int qr, int l, int r)
{
    long long _sum = 0;
    int mid = (l + r) / 2;
    if (ql <= l && r <= qr)
    {
        return sum[o];
    }
    else
    {
        if (mid >= ql)
        {
            _sum += query(o * 2, ql, qr, l, mid);
        }
        if (mid < qr)
        {
            _sum += query(o * 2 + 1, ql, qr, mid + 1, r);
        }
    }
    return _sum;
}
long long query(int l, int r)
{
    return query(1, l, r, 1, n);
}
int main()
{
    n = readInt();
    for (int i = 1; i <= n; i++)
    {
        a[i] = readInt();
    }
    build(1, 1, n);
    m = readInt();
    for (int i = 1; i <= m; i++)
    {
        int k, l, r;
        k = readInt();
        l = readInt();
        r = readInt();
        if (k == 1)
        {
            write(query(l, r));
            putchar('\n');
        }
        else
        {
            update(l, r);
        }
    }
    return 0;
}