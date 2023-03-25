#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
const int MAXLOGN = 20;
int n, q;
int nums[MAXN + 5];
int dmax[MAXN + 5][MAXLOGN + 5];
int dmin[MAXN + 5][MAXLOGN + 5];
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
void write(int x)
{
    if (x < 0)
    {
        putchar('-'), x = -x;
    }
    if (x > 9)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
    return;
}
void init()
{
    for (int i = 1; i <= n; i++)
    {
        dmax[i][0] = nums[i];
        dmin[i][0] = nums[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            dmax[i][j] = max(dmax[i][j - 1], dmax[i + (1 << (j - 1))][j - 1]);
            dmin[i][j] = min(dmin[i][j - 1], dmin[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int findx(int l, int r)
{
    int k = 0;
    while ((1 << (k + 1)) <= (r - l + 1))
    {
        k++;
    }
    return max(dmax[l][k], dmax[r - (1 << k) + 1][k]) - min(dmin[l][k], dmin[r - (1 << k) + 1][k]);
}
int main()
{
    n = readInt();
    q = readInt();
    for (int i = 1; i <= n; i++)
    {
        nums[i] = readInt();
    }
    init();
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        l = readInt();
        r = readInt();
        write(findx(l, r));
        putchar('\n');
    }
    return 0;
}