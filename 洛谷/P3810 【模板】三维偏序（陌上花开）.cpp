#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXK = 2e5 + 5;
int n, k;
struct Node
{
    int a, b, c;
    int cnt, ans;
};
int cnt_of_node = 0, cnt_of_same_node = 0;
int res[MAXN];
Node node[MAXN], node1[MAXN];
bool cmp1(const Node a, const Node b)
{
    if (a.a == b.a)
    {
        if (a.b == b.b)
        {
            return a.c < b.c;
        }
        return a.b < b.b;
    }
    return a.a < b.a;
}
bool cmp2(const Node a, const Node b)
{
    if (a.b == b.b)
    {
        return a.c < b.c;
    }
    return a.b < b.b;
}

int s[MAXK];
int lowbit(int x)
{
    return x & (-x);
}
void add(int x, int v)
{
    while (x <= k)
    {
        s[x] += v;
        x += lowbit(x);
    }
}
int query(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += s[x];
        x -= lowbit(x);
    }
    return ans;
}

void cdq(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    cdq(l, mid), cdq(mid + 1, r);
    sort(node1 + l, node1 + mid + 1, cmp2), sort(node1 + mid + 1, node1 + r + 1, cmp2);
    int i = mid + 1, j = l;
    while (i <= r)
    {
        while (j <= mid && node1[i].b >= node1[j].b)
        {
            add(node1[j].c, node1[j].cnt);
            j++;
        }
        node1[i].ans += query(node1[i].c);
        i++;
    }
    for (i = l; i < j; i++)
    {
        add(node1[i].c, -node1[i].cnt);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i].a >> node[i].b >> node[i].c;
    }
    sort(node + 1, node + n + 1, cmp1);
    for (int i = 1; i <= n; i++)
    {
        cnt_of_same_node++;
        if (node[i].a != node[i + 1].a || node[i].b != node[i + 1].b || node[i].c != node[i + 1].c)
        {
            node1[++cnt_of_node].a = node[i].a, node1[cnt_of_node].b = node[i].b, node1[cnt_of_node].c = node[i].c, node1[cnt_of_node].cnt = cnt_of_same_node, cnt_of_same_node = 0;
        }
    }
    cdq(1, cnt_of_node);
    for (int i = 1; i <= cnt_of_node; i++)
    {
        res[node1[i].cnt + node1[i].ans - 1] += node1[i].cnt;
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}