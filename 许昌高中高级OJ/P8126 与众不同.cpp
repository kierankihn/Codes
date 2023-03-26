#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
const int MAXLOGN = 20;
int n, q;
int nums[MAXN + 5];
int cnt[MAXN + 5];
int start[MAXN + 5];
int pre[MAXN + 5];
int d[MAXN + 5][MAXLOGN + 5];
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
int pren(int pos)
{
    if (pre[pos] != -1)
    {
        return pre[pos];
    }
    int tmp = pos - 1;
    while (nums[tmp] != nums[pos])
    {
        if (tmp < 1)
        {
            break;
        }
        tmp--;
    }
    return pre[pos] = tmp;
}
int cntn(int pos)
{
    if (cnt[pos] != -1)
    {
        return cnt[pos];
    }
    int prepos = pren(pos);
    if (nums[pos] != nums[pos - 1])
    {
        if (cntn(pos - 1) < pos - prepos)
        {
            start[pos] = start[pos - 1];
        }
        else
        {
            start[pos] = prepos + 1;
        }
        return cnt[pos] = min(cntn(pos - 1) + 1, pos - prepos);
    }
    start[pos] = pos;
    return cnt[pos] = 1;
}
void init()
{
    for (int i = 1; i <= n; i++)
    {
        d[i][0] = cnt[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
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
    return max(d[l][k], d[r - (1 << k) + 1][k]);
}
int main()
{
    memset(cnt, -1, sizeof(cnt));
    memset(pre, -1, sizeof(pre));
    n = readInt();
    q = readInt();
    for (int i = 1; i <= n; i++)
    {
        nums[i] = readInt();
        cntn(i);
    }
    init();
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << start[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << pre[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << cnt[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i <= q; i++)
    {
        int l, r, k = 1;
        l = readInt();
        r = readInt();
        l++;
        r++;
        while (start[k] < l)
        {
            k++;
        }
        write(max(start[k] - l + 1, k <= r ? findx(k, r) : min(k - 1, r) - max(start[k - 1], l) + 1));
        putchar('\n');
    }
    return 0;
}