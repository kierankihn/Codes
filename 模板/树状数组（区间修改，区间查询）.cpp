#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
int n, q;
int a[MAXN + 5];
int s[MAXN + 5];
int d[MAXN + 5];
inline int readInt()
{
    int res = 0;
    int w = 1;
    char ch;
    ch = getchar();
    if (ch == '-')
    {
        w = -1;
    }
    while (!(ch <= '9' && ch >= '0'))
    {
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
    {
        res = res * 10 + (int)(ch - '0');
        ch = getchar();
    }
    return res * w;
}
inline int lowbit(int x)
{
    return x & (-x);
}
int update(int *A, int pos, int x)
{
    while (pos <= n)
    {
        A[pos] += x;
        pos += lowbit(x);
    }
    return x;
}
int update(int l, int r, int x)
{
    update(s, l, x);
    update(s, r + 1, -x);
    update(d, l - 1, (l - 1) * x);
    update(d, r + 1, r * x);
    return x;
}
int query(int *A, int pos)
{
    int res = 0;
    while (pos > 0)
    {
        res += A[pos];
        pos -= lowbit(pos);
    }
    return res;
}
int query(int l, int r)
{
    int res = query(s, r) * r - query(s, l - 1) * (l - 1);
    res -= query(d, r) - query(d, l - 1);
    return res;
}
int main()
{
    // n = readInt();
    // q = readInt();
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        update(i, i, x);
        // update(i, i, readInt());
    }
    for (int i = 1; i <= q; i++)
    {
        if (readInt() == 1)
        {
            int x, y, a;
            cin >> x >> y >> a;
            update(x, y, a);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << query(x, y) << endl;
        }
    }
    return 0;
}