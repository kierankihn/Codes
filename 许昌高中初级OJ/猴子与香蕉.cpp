#include <bits/stdc++.h>
#define Mod 1000000007
#define eps 1e-6
#define ll long long
#define INF 0x3f3f3f3f
#define MEM(x, y) memset(x, y, sizeof(x))
#define Maxn 1000
using namespace std;
struct node
{
    int l, s, h; // 长 宽 高
    node(int l, int s, int h) : l(l), s(s), h(h) {}
    bool operator<(const node &c) const // 从小到大排序
    {
        if (l == c.l)
            return s < c.s;
        return l < c.l;
    }
};
vector<node> v;
int dp[Maxn];
int main()
{
    int n, k = 0;
    while (cin >> n && n != 0)
    {
        k++;
        v.clear(); // 清空，初始化
        MEM(dp, 0);
        int cnt = 0;
        int a, b, c;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b >> c; // 依次存入
            v.push_back(node(a, b, c));
            v.push_back(node(a, c, b));
            v.push_back(node(b, a, c));
            v.push_back(node(b, c, a));
            v.push_back(node(c, b, a));
            v.push_back(node(c, a, b));
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            dp[i] = v[i].h;
            for (int j = i - 1; j >= 0; j--)
            {
                if (v[j].l < v[i].l && v[j].s < v[i].s && dp[j] + v[i].h > dp[i])
                    dp[i] = dp[j] + v[i].h;
            }
            if (dp[i] > ans)
                ans = dp[i];
        }
        cout << "Case " << k << ": maximum height = " << ans << endl;
    }
    return 0;
}