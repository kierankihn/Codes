#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int n, m;
int vis[MAXN + 5][MAXN + 5];
int graph[MAXN + 5][MAXN + 5];
queue<int> ans;
bool dfs(int x, int cnt)
{
    bool isok = false;
    if (cnt == graph[0][0])
    {
        ans.push(x);
        return true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (graph[x][i] && (!vis[x][i]) && (!vis[i][x]))
        {
            vis[i][x] = vis[x][i] = 1;
            if (!isok)
            {
                isok = dfs(i, cnt + 1);
                if (isok)
                {
                    ans.push(x);
                    break;
                }
            }
            vis[i][x] = vis[x][i] = 0;
        }
    }
    return isok;
}
int main()
{
    cin >> n >> m;
    memset(vis, 0, sizeof(0));
    for (int i = 1; i <= m; i++)
    {
        int tmpx, tmpy;
        cin >> tmpx >> tmpy;
        graph[tmpx][tmpy] = 1;
        graph[tmpy][tmpx] = 1;
        graph[0][0]++;
        graph[tmpx][0]++;
        graph[tmpy][0]++;
    }
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (graph[i][0] % 2 == 1)
        {
            tmp++;
        }
    }
    if ((tmp != 0) && (tmp != 2))
    {
        cout << "NO\n";
        return 0;
    }
    if (tmp == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            if (graph[i][0] % 2 == 1)
            {
                dfs(i, 0);
            }
        }
    }
    if (tmp == 0)
    {
        dfs(1, 0);
    }
    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;
    return 0;
}