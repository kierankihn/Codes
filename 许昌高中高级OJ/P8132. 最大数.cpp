#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
const int INF = 0x3f3f3f3f;
int n, m, p, a, l;
long long maxn[MAXN * 4 + 5];
inline int readChar()
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
void update(int o, int l, int r, int pos, int v)
{
    int mid = (l + r) / 2;
    if (l == r)
    {
        maxn[o] += v;
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
        maxn[o] = max(maxn[o * 2], maxn[o * 2 + 1]);
    }
}
void update(int pos, int v)
{
    update(1, 1, n, pos, v);
}
long long query(int o, int ql, int qr, int l, int r)
{
    long long _max = -INF;
    int mid = (l + r) / 2;
    if (ql <= l && r <= qr)
    {
        return maxn[o];
    }
    else
    {
        if (mid >= ql)
        {
            _max = max(_max, query(o * 2, ql, qr, l, mid));
        }
        if (mid < qr)
        {
            _max = max(_max, query(o * 2 + 1, ql, qr, mid + 1, r));
        }
    }
    return _max;
}
long long query(int l, int r)
{
    return query(1, l, r, 1, n);
}
int main()
{
    n = MAXN;
    l = a = 0;
    m = readInt();
    p = readInt();
    for (int i = 1; i <= m; i++)
    {
        int b;
        char k;
        k = readChar();
        b = readInt();
        if (k == 'A')
        {
            l++;
            update(l, (b + a) % p);
        }
        else
        {
            a = query(l - b + 1, l);
            write(a);
            putchar('\n');
        }
    }
    return 0;
}