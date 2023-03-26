#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
const int MAXLOGN = 20;
int n, q;
struct Edge
{
    int from;
    int to;
    int dis;
    Edge(int u, int v, int d) : from(u), to(v), dis(d)
    {
        // nothing
    }
};
int depth[MAXN + 5];
int fa[MAXN + 5][MAXLOGN + 5];
vector<Edge> edge;
vector<int> g[MAXN + 5];
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
void add(int u, int v, int d)
{
    edge.push_back(Edge(u, v, d));
    g[u].push_back(edge.size() - 1);
}
void dfs(int u, int f)
{
    depth[u] = depth[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= 20; i++)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto j : g[u])
    {
        int v = edge[j].to;
        if (v != f)
        {
            dfs(v, u);
        }
    }
}
int LCA(int x, int y)
{
    if (depth[x] < depth[y])
    {
        swap(x, y);
    }
    for (int i = 20; i >= 0; i--)
    {
        if (depth[fa[x][i]] >= depth[y])
        {
            x = fa[x][i];
        }
        if (x == y)
        {
            return x;
        }
    }
    for (int i = 20; i >= 0; i--)
    {
        if (fa[x][i] != fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}
int main()
{
    n = readInt();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        u = readInt();
        v = readInt();
        add(u, v, 1);
    }
    dfs(1, 0);
    q = readInt();
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        x = readInt();
        y = readInt();
        write(depth[x] + depth[y] - depth[LCA(x, y)] * 2);
        putchar('\n');
    }
    return 0;
}