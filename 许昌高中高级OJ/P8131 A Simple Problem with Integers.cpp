#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
const int INF = 0x3f3f3f3f;
int n, q;
long long a[MAXN * 4 + 5];
long long sum[MAXN * 4 + 5];
long long tag[MAXN * 4 + 5];
inline char readChar()
{
    char ch = getchar();
    while (!(isupper(ch) || islower(ch)))
    {
        ch = getchar();
    }
    return ch;
}
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
void pushdown(int o, int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    tag[o * 2] += tag[o];
    tag[o * 2 + 1] += tag[o];
    sum[o * 2] += tag[o] * (mid - l + 1);
    sum[o * 2 + 1] += tag[o] * (r - mid);
    tag[o] = 0;
}
long long query(int o, int ql, int qr, int l, int r)
{
    long long res = 0;
    int mid = (l + r) / 2;
    if (ql <= l && r <= qr)
    {
        return sum[o];
    }
    pushdown(o, l, r);
    if (mid >= ql)
    {
        res += query(o * 2, ql, qr, l, mid);
    }
    if (mid < qr)
    {
        res += query(o * 2 + 1, ql, qr, mid + 1, r);
    }
    return res;
}
long long query(int l, int r)
{
    return query(1, l, r, 1, n);
}
void update(int o, int ql, int qr, int l, int r, int v)
{
    int mid = (l + r) / 2;
    if (ql <= l && r <= qr)
    {
        sum[o] += (long long)v * (r - l + 1);
        tag[o] += v;
        return;
    }
    pushdown(o, l, r);
    if (mid >= ql)
    {
        update(o * 2, ql, qr, l, mid, v);
    }
    if (mid < qr)
    {
        update(o * 2 + 1, ql, qr, mid + 1, r, v);
    }
    sum[o] = sum[o * 2] + sum[o * 2 + 1];
}
void update(int l, int r, int v)
{
    update(1, l, r, 1, n, v);
}
int main()
{
    n = readInt();
    q = readInt();
    for (int i = 1; i <= n; i++)
    {
        a[i] = readInt();
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        char tmp = readChar();
        if (tmp == 'C')
        {
            int l, r, v;
            l = readInt();
            r = readInt();
            v = readInt();
            update(l, r, v);
        }
        else
        {
            int l, r;
            l = readInt();
            r = readInt();
            write(query(l, r));
            putchar('\n');
        }
    }
    return 0;
}