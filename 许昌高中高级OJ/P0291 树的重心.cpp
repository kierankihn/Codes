#include <bits/stdc++.h>
using namespace std;
const int MAXN=16000;
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
int n;
int fa[MAXN+5];
int dp[MAXN+5];
int ansn[MAXN+5];
vector<int> ans;
vector<Edge> edge;
vector<int> g[MAXN+5];
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
void dfs(int x,int father)
{
	fa[x]=father;
	for(int i=0;i<g[x].size();i++)
	{
		int v=edge[g[x][i]].to;
		if(!fa[v])
		{
			dfs(v,x);
		}
	}
}
int solve(int x)
{
	if(dp[x]!=-1)
	{
		return dp[x];
	}
	dp[x]=0;
	for(int i=0;i<g[x].size();i++)
	{
		int v=edge[g[x][i]].to;
		if(fa[v]==x)
		{
			dp[x]+=solve(edge[g[x][i]].to)+1;
		}
	}
	return dp[x];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	n=readInt();
	for(int i=1;i<n;i++)
	{
		int u,v;
		u=readInt(),v=readInt();
		add(u,v,1);
		add(v,u,1);
	}
	dfs(1,1);
	ans.push_back(0x3f3f3f3f);
	for(int i=1;i<=n;i++)
	{
		solve(i);
		int tmp=n-dp[i]-1;
		for(int j=0;j<g[i].size();j++)
		{
			int v=edge[g[i][j]].to;
			if(fa[v]==i)
			{
				tmp=max(tmp,dp[v]+1);
			}
		}
		ansn[i]=tmp;
		if(tmp<ans[0])
		{
			ans.clear();
			ans.push_back(tmp);
			ans.push_back(i);
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		write(dp[i]);
//		putchar(' ');
//	}
//	putchar('\n');
//	for(int i=1;i<=n;i++)
//	{
//		write(ansn[i]);
//		putchar(' ');
//	}
//	putchar('\n');
	write(ans[0]);
	putchar(' ');
	write(ans.size()-1);
	putchar('\n');
	for(int i=1;i<ans.size();i++)
	{
		write(ans[i]);
		putchar(' ');
	}
	putchar('\n');
    return 0;
}
