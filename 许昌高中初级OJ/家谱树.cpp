#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int n;
queue<int> q;
int deg[MAXN + 5];
vector<int> g[MAXN + 5];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u = i, v;
        while (cin >> v && v != 0)
        {
            g[i].push_back(v);
            deg[v]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u;
        u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < g[u].size(); i++)
        {
            deg[g[u][i]]--;
            if (deg[g[u][i]] == 0)
            {
                q.push(g[u][i]);
            }
        }
    }
    cout << endl;
    return 0;
}