#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6000;
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
int n, q;
int root;
int vis[MAXN + 5];
int nums[MAXN + 5];
int dp[MAXN + 5][3];
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
inline void write(int x)
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
int solve(int x, int k)
{
    if (dp[x][k] != -1)
    {
        return dp[x][k];
    }
    dp[x][k] = 0;
    if (k == 1)
    {
        dp[x][k] += nums[x];
        for (unsigned int i = 0; i < g[x].size(); i++)
        {
            int v = edge[g[x][i]].to;
            dp[x][k] += solve(v, 0);
        }
    }
    else
    {
        for (unsigned int i = 0; i < g[x].size(); i++)
        {
            int v = edge[g[x][i]].to;
            dp[x][k] += max(solve(v, 0), solve(v, 1));
        }
    }
    return dp[x][k];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    n = readInt();
    for (int i = 1; i <= n; i++)
    {
        nums[i] = readInt();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        u = readInt(), v = readInt();
        add(v, u, 1);
        vis[u] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            root = i;
            break;
        }
    }
    write(max(solve(root, 0), solve(root, 1)));
    return 0;
}
