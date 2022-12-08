#include <bits/stdc++.h>
using namespace std;
const int MAXN=20;
int n;
int mp[MAXN+5][MAXN+5];
int dp[MAXN+5];
int vis[MAXN+5];
int solve(int x)
{
	int ans=-2;
	if(dp[x]!=-1)
	{
		ans=dp[x];
	}
	else
	{
		int beforei=0;
		for(int i=1;i<=n;i++)
		{
			if(mp[i][x])
			{
				if((ans==-2)||(ans>solve(i)+mp[i][x]))
				{
					vis[beforei]=0;
					vis[i]=1;
					ans=solve(i)+mp[i][x];
					beforei=i;
				}
			}
		}
	}
	return dp[x]=ans;
}
int main()
{
	memset(mp,0,sizeof(mp));
	memset(vis,0,sizeof(vis));
	memset(dp,-1,sizeof(dp));
	dp[1]=0;
	cin>>n;
	vis[n]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>mp[i][j];
		}
	}
	cout<<solve(n)<<endl;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
}
