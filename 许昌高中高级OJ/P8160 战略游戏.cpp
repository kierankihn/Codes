#include <bits/stdc++.h>
using namespace std;
const int MAXN=1500;
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
int nums[MAXN+5];
int dp[MAXN+5][3];
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
		if(fa[v]==-1)
		{
			dfs(v,x);
		}
	}
}
int solve(int x,int k)
{
	if(dp[x][k]!=-1)
	{
		return dp[x][k];
	}
	dp[x][k]=0;
	if(k==0)
	{
		for(unsigned int i=0;i<g[x].size();i++)
		{
			int v=edge[g[x][i]].to;
			if(fa[v]==x)
			{
				dp[x][k]+=solve(v,1);
			}
		}
	}
	else
	{
		dp[x][k]+=1;
		for(unsigned int i=0;i<g[x].size();i++)
		{
			int v=edge[g[x][i]].to;
			if(fa[v]==x)
			{
				dp[x][k]+=min(solve(v,0),solve(v,1));
			}
		}
	}
	return dp[x][k];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	memset(fa,-1,sizeof(fa));
    n=readInt();
    for(int i=1;i<=n;i++)
    {
    	int id,k;
    	id=readInt(),k=readInt();
    	for(int j=1;j<=k;j++)
    	{
    		int v=readInt();
    		add(id,v,1);
    		add(v,id,1);
		}
	}
	dfs(1,1);
	write(min(solve(1,1),solve(1,0)));
	putchar('\n');
//	write(root);
//	putchar('\n');
//	for(int i=1;i<=n;i++)
//	{
//		write(solve(i,0));
//		putchar(' ');
//	}
//	putchar('\n');
//	for(int i=1;i<=n;i++)
//	{
//		write(solve(i,1));
//		putchar(' ');
//	}
//	putchar('\n');
    return 0;
}
