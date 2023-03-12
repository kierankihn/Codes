#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000;
const int MAXPOS = 35000;
int n;
int c[MAXPOS + 5];
int ans[MAXPOS + 5];
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
void update(int pos, int x)
{
    while (pos <= MAXPOS)
    {
        c[pos] += x;
        pos += lowbit(pos);
    }
}
int query(int pos)
{
    int res = 0;
    while (pos > 0)
    {
        res += c[pos];
        pos -= lowbit(pos);
    }
    return res;
}
int main()
{
    n = readInt();
    for (int i = 1; i <= n; i++)
    {
        int x = readInt() + 1, y = readInt() + 1;
        ans[query(x)]++;
        update(x, 1);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}