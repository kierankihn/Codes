#include <bits/stdc++.h>
using namespace std;
const int MAXN=300;
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
int n,q;
int nums[MAXN+5];
int dp[MAXN+5][MAXN+5];
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
void solve(int x)
{
	dp[x][0]=0;
	for(unsigned int i=0;i<g[x].size();i++)
	{
		int v=edge[g[x][i]].to;
		solve(v);
		for(int j=q;j>=0;j--)
		{
			for(int k=j;k>=0;k--)
			{
				dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[v][k]);
			}
		}
	}
	if(x!=0)
	{
		for(int j=q;j>=1;j--)
		{
			dp[x][j]=dp[x][j-1]+nums[x];
		}
	}
	return;
}
int main()
{
	memset(dp,-1,sizeof(dp));
    n=readInt(),q=readInt();
    for(int i=1;i<=n;i++)
    {
    	int from,to,dis;
    	from=readInt(),to=i,dis=readInt();
    	nums[to]=dis;
		add(from,to,dis);
	}
	solve(0);
	write(dp[0][q]);
    return 0;
}
