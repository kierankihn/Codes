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
int minn;
int fa[MAXN+5];
int dp[MAXN+5];
int dpu[MAXN+5];
int ans[MAXN+5];
int dist[MAXN+5][3];
int distf[MAXN+5][3];
map<pair<int,int>,int> mp;
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
int solvedist(int x)
{
	if(dist[x][1]!=-1)
	{
		return dist[x][1];
	}
	dist[x][1]=0;
	dist[x][2]=0;
	for(int i=0;i<g[x].size();i++)
	{
		Edge e=edge[g[x][i]];
		int v=edge[g[x][i]].to;
		if(fa[v]==x)
		{
			if((solvedist(v)+e.dis)>dist[x][1])
			{
				distf[x][2]=distf[x][1];
				distf[x][1]=v;
				dist[x][2]=dist[x][1];
				dist[x][1]=solvedist(v)+e.dis;
			}
			else if(solvedist(v)+e.dis>dist[x][2])
			{
				distf[x][2]=v;
				dist[x][2]=solvedist(v)+e.dis;
			}
		}
	}
	return dist[x][1];
}
int solveup(int x)
{
	if(x==1)
	{
		return 0;
	}
	if(dpu[x]!=-1)
	{
		return dpu[x];
	}
	return dpu[x]=solveup(fa[x])+mp[pair<int,int>(x,fa[x])];
}
int solve(int x)
{
	if(x==1)
	{
		return 0;
	}
	if(dp[x]!=-1)
	{
		return dp[x];
	}
	int& tmp=dp[x];
	if(distf[fa[x]][1]==x)
	{
		tmp=max(dist[fa[x]][2],solve(fa[x]))+mp[pair<int,int>(x,fa[x])];
	}
	else
	{
		tmp=max(dist[fa[x]][1],solve(fa[x]))+mp[pair<int,int>(x,fa[x])];
	}
	return dp[x];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	memset(dpu,-1,sizeof(dpu));
	memset(dist,-1,sizeof(dist));
	n=readInt();
	for(int i=1;i<n;i++)
	{
		int u,v,d;
		u=readInt(),v=readInt(),d=readInt();
		add(u,v,d);
		add(v,u,d);
		mp[pair<int,int>(u,v)]=d;
		mp[pair<int,int>(v,u)]=d;
	}
	dfs(1,1);
	solvedist(1);
	minn=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		solvedist(i);
		ans[i]=max(solve(i),dist[i][1]);
		minn=min(minn,ans[i]);
//		write(ans[i]);
//		putchar(' ');
//		write(solve(i));
//		putchar(' ');
//		write(dist[i][1]);
//		putchar('\n');
	}
	write(minn);
	putchar('\n');
    return 0;
}
