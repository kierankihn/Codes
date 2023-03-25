#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int n, m;
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
    update(1, 1, n, pos, v);
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
    m = readInt();
    for (int i = 1; i <= m; i++)
    {
        int k, a, b;
        k = readInt();
        a = readInt();
        b = readInt();
        // if (readInt() == 0)
        // {
        //     update(readInt(), readInt());
        // }
        // else
        // {
        //     write(query(readInt(), readInt()));
        //     putchar('\n');
        // }
        if (k == 0)
        {
            update(a, b);
        }
        else
        {
            write(query(a, b));
            putchar('\n');
        }
    }
    return 0;
}