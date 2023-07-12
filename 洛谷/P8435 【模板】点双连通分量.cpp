#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
int n, m;
vector<vector<int>> ans;

struct Edge
{
    int from, to;
    Edge(int u, int v) : from(u), to(v)
    {
    }
};
vector<Edge> edge;
vector<int> g[MAXN];
void addEdge(int u, int v)
{
    g[u].push_back(edge.size());
    edge.push_back(Edge(u, v));
}

int tot = 0;
int dfn[MAXN], low[MAXN];
bool cut[MAXN];
stack<int> s;
void tarjan(int u, int root)
{
    int cnt = 0;
    dfn[u] = low[u] = ++tot;
    s.push(u);
    if (g[u].size() == 0 && u == root)
    {
        ans.push_back(vector<int>{u});
    }
    for (auto &i : g[u])
    {
        Edge &e = edge[i];
        if (!dfn[e.to])
        {
            tarjan(e.to, root);
            low[u] = min(low[u], low[e.to]);
            if (low[e.to] >= dfn[u])
            {
                int tmp, k;
                vector<int> tmp_ans;
                do
                {
                    k = s.top();
                    s.pop();
                    tmp_ans.push_back(k);
                } while (k != e.to);
                tmp_ans.push_back(u);
                ans.push_back(tmp_ans);
            }
        }
        else
        {
            low[u] = min(low[u], dfn[e.to]);
        }
    }
    if (u == root && cnt >= 2)
    {
        cut[u] = true;
    }
    if (u != root && cnt >= 1)
    {
        cut[u] = true;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == v)
        {
            continue;
        }
        addEdge(u, v), addEdge(v, u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i, i);
        }
    }
    cout << ans.size() << endl;
    for (unsigned int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].size() << " ";
        for (unsigned int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}