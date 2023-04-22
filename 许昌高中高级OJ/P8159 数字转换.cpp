#include <bits/stdc++.h>
using namespace std;
const int MAXN=50000;
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
int ans;
int n;
int fa[MAXN+5];
int dp[MAXN+5][3];
int sum[MAXN+5];
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
void init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=n/i;j++)
		{
			sum[i*j]+=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(sum[i]<i)
		{
			add(sum[i],i,1);
			add(i,sum[i],1);
		}
	}
}
void dfs(int x,int father)
{
	fa[x]=father;
	for(unsigned int i=0;i<g[x].size();i++)
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
	if(dp[x][1]!=-1)
	{
		return dp[x][1];
	}
	dp[x][1]=0;
	dp[x][2]=0;
	for(unsigned int i=0;i<g[x].size();i++)
	{
		Edge e=edge[g[x][i]];
		int v=edge[g[x][i]].to;
		if(fa[v]==x)
		{
			if((solve(v)+e.dis)>dp[x][1])
			{
				dp[x][2]=dp[x][1];
				dp[x][1]=solve(v)+e.dis;
			}
			else if(solve(v)+e.dis>dp[x][2])
			{
				dp[x][2]=solve(v)+e.dis;
			}
		}
	}
	return dp[x][1];
}
int main()
{
	memset(dp,-1,sizeof(dp));
    n=readInt();
    ans=-1;
    init();
    dfs(1,1);
    for(int i=1;i<=n;i++)
    {
    	solve(i);
    	ans=max(ans,dp[i][1]+dp[i][2]);
	}
	write(ans);
	putchar('\n');
    return 0;
}
