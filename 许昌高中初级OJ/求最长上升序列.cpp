#include <bits/stdc++.h>
using namespace std;
const int MAXN=10000;
int n;
int ans=1;
int ansk;
int nums[MAXN+5];
int dp[MAXN+5][2];
int vis[MAXN+5];
int solve(int k)
{
	if(vis[k])
	{
		return dp[k][0];
	}
	else
	{
		for(int i=1;i<k;i++)
		{
			if(nums[k]>nums[i])
			{
				if(dp[k][0]<solve(i)+1)
				{
					dp[k][0]=solve(i)+1;
					dp[k][1]=i;
				}
				
			}
		}
	}
	vis[k]=1;
	return dp[k][0];
}
void print(int k)
{
	if(dp[k][0]!=1)
	{
		print(dp[k][1]);
	}
	cout<<nums[k]<<" ";
}
int main()
{
	memset(vis,0,sizeof(vis));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>nums[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(ans<solve(i))
		{
			ans=solve(i);
			ansk=i;
		}
	}
	cout<<ans<<endl;
	print(ansk);
	return 0;
} 
