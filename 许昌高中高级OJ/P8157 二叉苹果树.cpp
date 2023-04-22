#include <bits/stdc++.h>
using namespace std;
const int MAXN=100;
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
int solve(int x,int k)
{
	if(k==0)
	{
		return dp[x][k]=0;
	}
	if(k==1)
	{
		return dp[x][k]=nums[x];
	}
	if(g[x].size()==0)
	{
		return dp[x][k]=nums[x];
	}
	if(dp[x][k]!=-1)
	{
		return dp[x][k];
	}
	int lson,rson;
	lson=edge[g[x][0]].to;
	rson=edge[g[x][1]].to;
	for(int i=0;i<=k-1;i++)
	{
		dp[x][k]=max(dp[x][k],solve(lson,i)+solve(rson,k-i-1)+nums[x]);
	}
	return dp[x][k];
}
int main()
{
	memset(dp,-1,sizeof(dp));
    n=readInt(),q=readInt();
    for(int i=1;i<n;i++)
    {
    	int from,to,dis;
    	from=readInt(),to=readInt(),dis=readInt();
    	if(nums[to]==0)
    	{
    		nums[to]=dis;
			add(from,to,dis);
		}
    	else
    	{
    		nums[from]=dis;
			add(to,from,dis);
		}
	}
	write(solve(1,q+1));
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=q+1;j++)
//		{
//			write(solve(i,j));
//			putchar(' ');
//		}
//		putchar('\n');
//	}
    return 0;
}
