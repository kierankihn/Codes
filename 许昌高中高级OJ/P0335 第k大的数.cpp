#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
int n, q;
int c[MAXN + 5];
int nums[MAXN + 785];
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
        sum[o] = c[l];
        return;
    }
    int mid = (l + r) / 2;
    build(o * 2, l, mid);
    build(o * 2 + 1, mid + 1, r);
    sum[o] = sum[o * 2] + sum[o * 2 + 1];
}
void update(int o, int l, int r, int pos, int v)
{
    int mid = (l + r) / 2;
    if (l == r)
    {
        sum[o] += v;
        return;
    }
    else
    {
        if (pos <= mid)
        {
            update(o * 2, l, mid, pos, v);
        }
        else
        {
            update(o * 2 + 1, mid + 1, r, pos, v);
        }
        sum[o] = sum[o * 2] + sum[o * 2 + 1];
    }
}
void update(int pos, int v)
{
    update(1, 1, MAXN, pos, v);
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
    return query(1, l, r, 1, MAXN);
}
int findx(int o, int l, int r, int pos)
{
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2;
    if (pos <= sum[o * 2])
    {
        return findx(o * 2, l, mid, pos);
    }
    else
    {
        return findx(o * 2 + 1, mid + 1, r, pos - sum[o * 2]);
    }
    return -1;
}
int findx(int pos)
{
    return findx(1, 1, MAXN, pos);
}
int main()
{
    n = readInt();
    q = readInt();
    for (int i = 1; i <= n; i++)
    {
        nums[i] = readInt();
        c[nums[i]]++;
    }
    build(1, 1, MAXN);
    for (int i = 1; i <= q; i++)
    {
        int k = readInt();
        if (k == 1)
        {
            int pos = readInt();
            write(findx(pos));
            putchar('\n');
            // int l,r;
            // l = readInt();
            // r = readInt();
            // write(query(l, r));
        }
        else
        {
            int pos, x;
            pos = readInt();
            x = readInt();
            update(nums[pos], -1);
            update(x, 1);
            nums[pos] = x;
        }
    }
    return 0;
}
