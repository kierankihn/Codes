#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, m;
bool color[MAXN];
bool vis[MAXN];
bool isinsta[MAXN];
struct Edge
{
    int u, v;
    Edge(int u_, int v_) : u(u_), v(v_)
    {
    }
};
vector<Edge> edge;
vector<int> g[MAXN];
void add(int u, int v)
{
    g[u].push_back(edge.size());
    edge.push_back(Edge(u, v));
}
bool solve()
{
    stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            s.push(i);
            while (!s.empty())
            {
                int u = s.top();
                s.pop();
                vis[u] = true;
                isinsta[u] = false;
                for (int &j : g[u])
                {
                    Edge &e = edge[j];
                    if (vis[e.v] && (color[u] != color[e.v]))
                    {
                        return true;
                    }
                    if (!vis[e.v] && (color[u] != color[e.v]) && (!isinsta[e.v]))
                    {
                        isinsta[e.v] = true;
                        s.push(e.v);
                    }
                }
                color[u] = !color[u];
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
    }
    if (solve())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}