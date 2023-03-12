#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
int n, q;
long long a[MAXN + 5];
long long s[MAXN + 5];
int readInt()
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
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    n = readInt();
    q = readInt();
    for (int i = 1; i <= n; i++)
    {
        a[i] = readInt();
    }
    for (int i = 1; i <= q; i++)
    {
        int k, x, y, c;
        k = readInt();
        if (k == 1)
        {
            x = readInt();
            y = readInt();
            c = readInt();
            add(x, c);
            add(y + 1, -c);
        }
        else
        {
            c = readInt();
            cout << query(c) + a[c] << endl;
        }
    }
    return 0;
}