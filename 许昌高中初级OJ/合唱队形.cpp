#include <bits/stdc++.h>
using namespace std;
const int MAXN=100;
int n;
int ans=0;
int h[MAXN+5];
int dp[MAXN+5][2];
int solve(int k)
{
	if(dp[k][0]==-1 && dp[k][1]==-1)
	{
		dp[k][0]=dp[k][1]=1;
		for(int i=k+1;i<=n;i++)
		{
			solve(i);
			if(h[k]<h[i])
			{
				dp[k][1]=max(dp[k][1],dp[i][0]+1);
				dp[k][1]=max(dp[k][1],dp[i][1]+1);
			}
			if(h[k]>h[i])
			{
				dp[k][0]=max(dp[k][0],dp[i][0]+1);
			}
		}
	}
	return max(dp[k][0],dp[k][1]);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,solve(i));
	}
	cout<<n-ans<<endl;
	
	return 0;
}
