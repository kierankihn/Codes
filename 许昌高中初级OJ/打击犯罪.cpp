#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n;
int fa[MAXN + 5];
int cnt[MAXN + 5];
vector<int> connect[MAXN + 5];
void init(int k)
{
    memset(cnt, 0, sizeof(cnt));
    memset(fa, 0, sizeof(fa));
    for (int i = k + 1; i <= n; i++)
    {
        fa[i] = i;
    }
}
int find(int x)
{
    while (fa[x] != x)
    {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void unio(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return;
    }
    fa[y] = x;
}
bool check(int k)
{
    int cnt = 0;
    init(k);
    for (int i = k + 1; i <= n; i++)
    {
        for (int j = 0; j < connect[i].size(); j++)
        {
            if (connect[i][j] > k)
            {
                unio(i, connect[i][j]);
            }
        }
    }
    for (int i = k + 1; i <= n; i++)
    {
        if (find(i) == i)
        {
            cnt++;
        }
    }
    return cnt < (n / 2);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            int tmp;
            cin >> tmp;
            connect[i].push_back(tmp);
        }
    }
    // int l = 1, r = n;
    // int ans;
    // while (l < r)
    // {
    //     int mid = (l + r) / 2;
    //     if (check(mid))
    //     {
    //         ans = mid;
    //         r = mid - 1;
    //     }
    //     else
    //     {
    //         l = mid + 1;
    //     }
    // }
    // cout << ans << endl;
    init(1);
    unio(5, 6);
    unio(6, 5);
    return 0;
}