#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000;
int n, m;
int ans = 0;
int cnt = 0;
queue<pair<int, int>> q;
int deg[MAXN + 5];
vector<int> g[MAXN + 5];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> v >> u;
        g[u].push_back(v);
        deg[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
        {
            q.push(pair<int, int>(i, 100));
        }
    }
    while (!q.empty())
    {
        pair<int, int> u;
        u = q.front();
        q.pop();
        ans += u.second;
        cnt++;
        for (int i = 0; i < g[u.first].size(); i++)
        {
            deg[g[u.first][i]]--;
            if (deg[g[u.first][i]] == 0)
            {
                q.push(pair<int, int>(g[u.first][i], u.second + 1));
            }
        }
    }
    if (cnt == n)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "Poor Xed\n";
    }
    return 0;
}