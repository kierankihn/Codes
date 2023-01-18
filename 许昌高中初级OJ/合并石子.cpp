#include <bits/stdc++.h>
using namespace std;
const int MAXN=100; 
int n;
int cnt[MAXN+5];
int nums[MAXN+5];
int dp[MAXN+5][MAXN+5];
int solve(int x,int y)
{
	int res=1e8;
	if(dp[x][y]!=-1)
	{
		return dp[x][y];
	}
	else
	{
		for(int i=x+1;i<=y;i++)
		{
			res=min(res,solve(x,i-1)+solve(i,y)+cnt[y]-cnt[x-1]);
		}
	}
	return dp[x][y]=res;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>n;
	cnt[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>nums[i];
		cnt[i]=cnt[i-1]+nums[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=0;
	}
	cout<<solve(1,n);
	return 0;
}